/* 
 * Project: NOMURA Programing Contest B - Postdocs
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/05/30
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstring>
using namespace std;

char t[200000];
int k;

void solve() {

    for (int i=0;i<strlen(t);i++) {
        if (t[i] == '?') {
            t[i] = 'D';
        }
    }
    printf("%s\n", t);

}

int main() {

    scanf("%s", t);

    solve();

}