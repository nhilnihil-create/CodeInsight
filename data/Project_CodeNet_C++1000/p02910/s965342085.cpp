/* 
 * Project: AtCoder Beginners Contest 141 B - Tap Dance
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/20
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
#include <cstring>
using namespace std;

char s[100];

void solve() {

    uint32_t length = strlen(s);
    for (int i=0;i<length;i++) {
        if ((i+1)&1) {
            if (s[i] != 'R' && s[i] != 'U' && s[i] != 'D') {
                printf("No\n");
                return;
            }
        } else {
            if (s[i] != 'L' && s[i] != 'U' && s[i] != 'D') {
                printf("No\n");
                return;
            }
        }
    }
    printf("Yes\n");

}

int main() {

    scanf("%s", s);

    solve();

}