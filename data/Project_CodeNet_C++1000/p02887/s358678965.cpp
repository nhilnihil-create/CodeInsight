/* 
 * Project: AtCoder Beginners Contest 143 C - Slimes
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/18
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstdint>
using namespace std;

uint32_t n;
char s[100000];

void solve() {

    uint32_t cnt = n;
    for (int i=0;i<n-1;i++) {
        if (s[i] == s[i+1])
            cnt--;
    }
    printf("%d\n", cnt);
}

int main() {

    scanf("%d", &n);
    scanf("%s", s);

    solve();
}