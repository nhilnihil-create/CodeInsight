/* 
 * Project: AtCoder Beginners Contest 166 C - Peaks
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/05/03
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <iostream>
#include <cstdio>
#include <cmath>
#include <cstring>
using namespace std;

int n, m;
int h[100000];
int a[100000];
int b[100000];

void solve() {
    int ma[n+1];
    memset(ma, 0, sizeof(ma));
    for (int i=0;i<m;i++) {
        ma[a[i]] = max(ma[a[i]], h[b[i]-1]);
        ma[b[i]] = max(ma[b[i]], h[a[i]-1]);
    }
    int cnt = 0;
    for (int i=1;i<=n;i++) {
        if (h[i-1] > ma[i])
            cnt++;
    }
    printf("%d\n", cnt);
}

int main() {

    scanf("%d", &n);
    scanf("%d", &m);
    for (int i=0;i<n;i++) {
        scanf("%d", &h[i]);
    }
    for (int i=0;i<m;i++) {
        scanf("%d", &a[i]);
        scanf("%d", &b[i]);
    }

    solve();
}