/* 
 * Project: Panasonic programing Contest B - Bishop
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/12
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include<cstdio>
using namespace std;

long h, w;

void solve() {

    if (h^1 && w^1)
        printf("%ld\n", ((h*w)+1)/2);
    else
        printf("%d\n",1);

}

int main() {

    scanf("%ld", &h);
    scanf("%ld", &w);

    solve();

}
