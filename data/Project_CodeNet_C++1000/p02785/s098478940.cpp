/* 
 * Project: AtCoder Beginners Contest 153 C - Fennec vs Monster
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/03
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <stdio.h>
#include <algorithm>
#include <numeric>
using namespace std;

int n;
long h[200000];
int k;

void solve() {

    if (k >= n) {
        printf("0\n");
        return;
    }

    sort(h, h+n);
    long attack = accumulate(h, h+n-k, 0L);
    printf("%ld\n", attack);
}

int main() {

    scanf("%d", &n);
    scanf("%d", &k);
    for (int i=0;i<n;i++) {
        scanf("%ld", &h[i]);
    }

    solve();

}