/* 
 * Project: AtCoder Beginners Contest 135 A - Harmony
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/09/11
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
#include <algorithm>
using namespace std;

int64_t a, b;

void solve() {

    uint32_t min_val = min(a, b);
    uint32_t max_val = max(a, b);
    uint32_t diff = max_val - min_val;
    if (diff%2 == 0) {
        printf("%d\n", diff/2+min_val);
    } else {
        printf("IMPOSSIBLE\n");
    }
}

int main() {

    scanf("%lld", &a);
    scanf("%lld", &b);

    solve();

}