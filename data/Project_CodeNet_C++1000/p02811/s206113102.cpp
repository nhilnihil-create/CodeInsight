/* 
 * Project: AtCoder Beginners Contest 150 A - 500 Yen Coins
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/20
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstring>
using namespace std;

int k, x;

void solve() {

    if (500 * k >= x)
        printf("Yes\n");
    else
        printf("No\n");
}

int main() {

    scanf("%d", &k);
    scanf("%d", &x);

    solve();

}