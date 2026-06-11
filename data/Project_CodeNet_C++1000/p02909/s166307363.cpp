/* 
 * Project: AtCoder Beginners Contest 141 A - Weather Prediction
 * Author: toms74209200 <https://github.com/toms74209200>
 *
 * Created on 2020/08/19
 * Copyright (c) 2020 toms74209200
 * 
 * This software is released under the MIT License.
 * http://opensource.org/licenses/mit-license.php
 */
#include <iostream>
#include <string>
#include <vector>
using namespace std;

string s;

void solve() {

    const static vector<string> WEATHERS = { "Sunny", "Cloudy", "Rainy", "Sunny"};

    for (auto itr=WEATHERS.begin();itr!=WEATHERS.end();++itr) {
        if (s == *itr) {
            cout << *++itr << "\n";
            return;
        }
    }

}

int main() {

    cin >> s;

    solve();

}