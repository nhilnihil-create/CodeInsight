/* 
 * Project: AtCoder Beginners Contest 150 B - Count ABC
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/20
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
char s[50];

void solve() {

    int cnt = 0;
    bool flag_a = false;
    bool flag_b = false;
    for (int i=0;i<n;i++) {
        if (flag_b) {
            if (s[i] == 'C')
                cnt++;
            flag_b = false;
        }
        if (flag_a) {
            if (s[i] == 'B')
                flag_b = true;
            flag_a = false;
        }
        flag_a = s[i] == 'A';
    }
    printf("%d\n", cnt);
}

int main() {

    scanf("%d", &n);
    scanf("%s", s);

    solve();

}