/* 
 * Project: AtCoder Beginners Contest 154 A - Remaining Balls
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/30
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstring>
using namespace std;

char s[10];
char t[10];
char u[10];
int a, b;

void solve() {

    if (!strncmp(u, s, strlen(u)))
        printf("%d %d\n", a-1, b);
    else
        printf("%d %d\n", a, b-1);

}

int main() {

    scanf("%s", s);
    scanf("%s", t);
    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%s", u);

    solve();

}