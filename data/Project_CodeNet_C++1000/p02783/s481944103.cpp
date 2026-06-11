/* 
 * Project: AtCoder Beginners Contest 153 A - Serval vs Monster
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/01
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstring>
using namespace std;


int a, h;

void solve() {

    if (h%a > 0)
        printf("%d\n", h/a+1);
    else
        printf("%d\n", h/a);
}

int main() {

    scanf("%d", &h);
    scanf("%d", &a);

    solve();

}