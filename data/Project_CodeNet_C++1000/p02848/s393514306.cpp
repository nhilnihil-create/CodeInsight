/* 
 * Project: AtCoder Beginners Contest 146 B - ROT N
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/08
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstring>
using namespace std;

int n;
char s[10000];

void solve() {

    for (int i=0;s[i]!='\0';i++) {
        s[i] = s[i] + n;
        if (s[i] > 'Z')
            s[i] -= 26;
    }
    printf("%s\n", s);

}

int main() {

    scanf("%d", &n);
    scanf("%s", s);

    solve();

}