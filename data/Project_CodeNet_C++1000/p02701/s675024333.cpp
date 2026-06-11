/* 
 * Project: AtCoder Beginners Contest 164 C - gacha
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/07
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <string>
#include <map>
using namespace std;

int n;
map<string, int> items;

void solve() {
    int num = items.size();
    printf("%d\n", num);
}

int main() {

    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        char s[10];
        scanf("%s", s);
        items[(string)s]++;
    }

    solve();
}