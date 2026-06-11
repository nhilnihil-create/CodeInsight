
// Problem: A - Rainy Season
// Contest: AtCoder - AtCoder Beginner Contest 175
// URL: https://atcoder.jp/contests/abc175/tasks/abc175_a
// Parsed on: 2020-09-02 13:00:06
// Memory Limit: 1024 MB
// Time Limit: 2000 ms
//
// Powered by CP Editor (https://cpeditor.org)

#include <algorithm>
#include <cmath>
#include <iostream>
#include <numeric>
#include <string>
#include <vector>

#define fastio                        \
    ios_base::sync_with_stdio(false); \
    cin.tie(0);

using namespace std;

int main() {
    string s;
    cin >> s;
    if (s == "SSS")
        cout << "0";
    else if (s == "SSR")
        cout << "1";
    else if (s == "SRS")
        cout << "1";
    else if (s == "SRR")
        cout << "2";
    else if (s == "RSS")
        cout << "1";
    else if (s == "RSR")
        cout << "1";
    else if (s == "RRS")
        cout << "2";
    else if (s == "RRR")
        cout << "3";
    else
        return -2;
    return 0;
}
