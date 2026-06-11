/* 
 * Project: AtCoder Beginners Contest 154 B - I miss you...
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/30
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
using namespace std;

char s[100];

void solve() {

    char *ptr;
    ptr = &s[0];

    while (*ptr ^ '\0') {
        printf("x");
        ptr++;
    }
    printf("\n");
}

int main() {

    scanf("%s", s);

    solve();

}