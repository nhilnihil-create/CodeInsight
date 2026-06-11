/* 
 * Project: Panasonic programing Contest C - Sqrt Inequality
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/12
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cmath>
using namespace std;

long a, b, c;

void solve() {

    long diff = c - a -b;
    long ab = (a*b) << 2;

    if (diff > 0 && diff*diff > ab)
        printf("Yes\n");
    else
        printf("No\n");

}

int main() {

    scanf("%ld", &a);
    scanf("%ld", &b);
    scanf("%ld", &c);

    solve();

}
