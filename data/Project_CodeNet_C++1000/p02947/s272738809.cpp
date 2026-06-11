/* 
 * Project: AtCoder Beginners Contest 137 C - Green Bin
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/09/01
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <iostream>
#include <cstdint>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

uint32_t n;
vector<string> s;

void solve() {

    map<string, uint64_t> s_bin;
    for (int i=0;i<n;i++) {
        sort(s[i].begin(), s[i].end());
        s_bin[s[i]]++;
    }
    uint64_t cnt = 0;
    for (auto i : s_bin) {
        cnt += i.second*(i.second-1)/2;
    }
    printf("%lld\n", cnt);

}

int main() {

    cin >> n;
    s.resize(n);
    for (int i=0;i<n;i++) {
        cin >> s[i];
    }

    solve();
}