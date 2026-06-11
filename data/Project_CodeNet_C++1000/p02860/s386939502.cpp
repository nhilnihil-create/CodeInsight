/* 
 * Project: AtCoder Beginners Contest 145 B - Echo
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/08
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;

int n;
string s;

void solve() {

    int s_length = s.size();
    if (s.substr(0, s_length/2) == s.substr(s_length/2, s_length))
        printf("Yes\n");
    else
        printf("No\n");

}

int main() {

    scanf("%d", &n);
    cin >> s;

    solve();

}