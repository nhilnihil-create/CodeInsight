/* 
 * Project: AtCoder Beginners Contest 153 B - Common Raccoon vs Monster
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/02
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <stdio.h>
#include <algorithm>
#include <numeric>
using namespace std;

int h;
int n;
int a[100000];

void solve() {

    if (h - accumulate(a, a+n, 0) <= 0)
        printf("Yes\n");
    else
        printf("No\n");
}

int main() {

    scanf("%d", &h);
    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }

    solve();

}