#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

int main() {
    string s;
    cin >> s;

    int d = 0;
    for (char c: s) {
        d += (c - '0');
        d %= 9;
    }
    cout << (d == 0 ? "Yes": "No") << "\n";
    return 0;
}