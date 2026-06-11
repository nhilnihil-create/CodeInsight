/* 
 * Project: AtCoder Beginners Contest 151 C - Welcome to AtCoder
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/19
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

int n;
int m;

int main() {

    cin >> n >> m;
    vector<bool> is_acs(n, false);
    vector<int> wa_cnt(n, 0);
    int ac_cnt = 0;
    int penalty = 0;
    for (int i=0;i<m;i++) {
        int p;
        string s;
        cin >> p >> s;
        if (is_acs[p-1])
            continue;
        if (!s.compare("AC")) {
            is_acs[p-1] = true;
            ac_cnt++;
            penalty += wa_cnt[p-1];
        }
        else
            wa_cnt[p-1]++;
    }
    cout << ac_cnt << " " << penalty << "\n";

}