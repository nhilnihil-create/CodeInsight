/* 
 * Project: AtCoder Beginners Contest 148 B - Strings with the Same Length
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/31
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <algorithm>
#include <numeric>
using namespace std;

int n;
char s[100];
char t[100];

void solve() {

    for (int i=0;i<n;i++) {
        printf("%c", s[i]);
        printf("%c", t[i]);
    }
    printf("\n");
    return;
}

int main() {

    scanf("%d", &n);
    scanf("%s", s);
    scanf("%s", t);

    solve();

}