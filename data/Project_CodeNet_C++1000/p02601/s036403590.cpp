/* 
 * Project: M-SOLUTIONS プロコンオープン 2020 B - Magic 2
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/25
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <string>
#include <iostream>
using namespace std;

int a, b, c;
int k;

void solve() {

    if (c > b && b > a) {
        printf("Yes\n");
        return;
    }

    int cnt = 0;
    while (a >= b) {
        b *= 2;
        cnt++;
    }
    while (b >= c) {
        c *= 2;
        cnt++;
        if (cnt > k) {
            printf("No\n");
            return;
        }
    }
    if (cnt <= k) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }
}

int main() {

    scanf("%d", &a);
    scanf("%d", &b);
    scanf("%d", &c);
    scanf("%d", &k);

    solve();

}