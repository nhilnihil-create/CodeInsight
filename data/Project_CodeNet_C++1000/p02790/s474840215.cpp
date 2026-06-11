/* 
 * Project: AtCoder Beginners Contest 152 B - Comparing Strings
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/13
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <stdio.h>
#include <algorithm>
#include <numeric>
using namespace std;

int a;
int b;

void solve() {

    if (a < b) {
        for (int i=0;i<b;i++) {
            printf("%d", a);
        }
    } else {
        for (int i=0;i<a;i++) {
            printf("%d", b);
        }
    }
    printf("\n");
}

int main() {

    scanf("%d", &a);
    scanf("%d", &b);

    solve();

}