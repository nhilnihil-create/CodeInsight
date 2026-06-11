/* 
 * Project: AtCoder Beginners Contest 154 C - Distinct or Not
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/04
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <algorithm>
using namespace std;

int n;
int a[200000];

void solve() {

    sort(a, a+n);
    for (int i=0;i<n-1;i++) {
        if (a[i+1] - a[i] == 0) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
    return;

}

int main() {

    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }

    solve();

}