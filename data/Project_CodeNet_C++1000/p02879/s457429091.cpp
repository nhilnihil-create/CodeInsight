/* 
 * Project: AtCoder Beginners Contest 144 A - 9x9
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/12
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
using namespace std;

uint32_t a;
uint32_t b;

void solve() {

    if (a > 9 || b > 9) {
        printf("-1\n");
        return;
    }

    printf("%d\n", a*b);

}

int main() {

    scanf("%d", &a);
    scanf("%d", &b);

    solve();

}