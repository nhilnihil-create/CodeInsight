/* 
 * Project: AtCoder Beginners Contest 139 A - Tenki
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/24
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
using namespace std;

char s[3];
char t[3];

void solve() {

    uint16_t cnt = 0;
    for (int i=0;i<3;i++) {
        cnt += (s[i] == t[i]);
    }
    printf("%d\n", cnt);

}

int main() {

    scanf("%s", s);
    scanf("%s", t);

    solve();

}