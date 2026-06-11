/* 
 * Project: AtCoder Beginners Contest 155 C - Poll
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/07/14
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <algorithm>
using namespace std;

int n;
vector<string> vec;
map<string,int> s;
typedef pair<string, int> value_type;

struct second_order {
    bool operator()(const value_type& x, const value_type& y) const {
      return x.second > y.second;
    }
};

void solve() {

    for (string e : vec) {
        s[e]++;
    }
    int max_cnt = 0;
    for (const auto& x : s) {
        int cnt = x.second;
        if (cnt > max_cnt) {
            max_cnt = cnt;
        }
    }
    for (auto iter = s.begin(); iter != s.end(); iter++) {
        if (iter->second == max_cnt) {
            printf("%s\n", iter->first.c_str());
        }
    }
}

int main() {

    scanf("%d", &n);
    for (int i=0;i<n;i++) {
        string str;
        cin >> str;
        vec.push_back(str);
        s[str] = 0;
    }

    solve();
}