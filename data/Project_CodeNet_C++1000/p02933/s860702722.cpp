/* 
 * Project: AtCoder Beginners Contest 138 A - Red or Not
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/27
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
using namespace std;

uint32_t a;
char s[10];

void solve() {

    if (a >= 3200)
        printf("%s\n", s);
    else
        printf("red\n");

}

int main() {

    scanf("%d", &a);
    scanf("%s", s);

    solve();

}