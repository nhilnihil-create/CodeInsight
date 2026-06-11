//
// Created by 26019 on 2020/6/14/014.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
vector<int> arr;

void solve() {
    string s;
    cin >> s;
    if (s == "MON") {
        cout << 6;
    } else if (s == "TUE") {
        cout << 5;
    } else if (s == "WED") {
        cout << 4;
    } else if (s == "THU") {
        cout << 3;
    } else if (s == "FRI") {
        cout << 2;
    } else if (s == "SAT") {
        cout << 1;
    } else {
        cout << 7;
    }
}

int main() {
    solve();
    return 0;
}
