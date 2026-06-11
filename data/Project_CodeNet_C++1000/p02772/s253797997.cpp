/* 
 * Project: AtCoder Beginners Contest 155 B - Papers, Please
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/06/24
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
int a[1000];

void solve() {

    for (int i=0;i<n;i++) {
        if (!(a[i] & 1)) {
            if (a[i]%3 != 0 && a[i]%5 != 0) {
                printf("DENIED\n");
                return;
            }
        }
    }
    printf("APPROVED\n");

}

int main() {

    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        scanf("%d", &a[i]);
    }

    solve();

}