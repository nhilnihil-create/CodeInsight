/* 
 * Project: AtCoder Beginners Contest 147 A - Blackjack
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/05
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
using namespace std;

int sum;

void solve() {

    if (sum > 21)
        printf("bust\n");
    else
        printf("win\n");

}

int main() {

    for (int i=0;i<3;i++) {
        int tmp = 0;
        scanf("%d", &tmp);
        sum += tmp;
    }

    solve();

}