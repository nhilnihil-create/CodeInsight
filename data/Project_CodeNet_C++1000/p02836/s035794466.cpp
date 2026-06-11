/* 
 * Project: AtCoder Beginners Contest 147 B - Palindrome-philia
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/06
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstring>
using namespace std;

char s[100];

void solve() {

    int cnt = 0;
    int s_length = strlen(s);
    int s_half = s_length/2;

    for (int i=0;i<s_half;i++) {
        if (s[i] != s[s_length-i-1]) {
            cnt++;
        }
    }
    printf("%d\n",cnt);

}

int main() {

    scanf("%s", s);

    solve();

}