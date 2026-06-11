/* 
 * Project: AtCoder Beginners Contest 143 A - Curtain
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/14
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

    if (a < 2*b)
        printf("0\n");
    else
        printf("%d\n", a-2*b);

}

int main() {

    scanf("%d", &a);
    scanf("%d", &b);

    solve();

}