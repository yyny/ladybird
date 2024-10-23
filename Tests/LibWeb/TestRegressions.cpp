/*
 * Copyright (c) 2021, David Tuin <davidot@serenityos.org>
 *
 * SPDX-License-Identifier: BSD-2-Clause
 */

#include <LibJS/Runtime/GlobalObject.h>
#include <LibJS/Runtime/Realm.h>
#include <LibJS/Runtime/VM.h>
#include <LibTest/TestCase.h>
#include <LibWeb/HTML/Storage.h>

TEST_CASE(PR1931_storage_internal_own_property_keys_does_not_loop_forever)
{
    auto vm = MUST(JS::VM::create());
    auto root_execution_context = JS::create_simple_execution_context<JS::GlobalObject>(*vm);
    auto& realm = *root_execution_context->realm;

    auto storage_object = realm.heap().allocate_without_realm<Web::HTML::Storage>(realm);

    EXPECT(MUST(storage_object->internal_own_property_keys()).is_empty());
}
