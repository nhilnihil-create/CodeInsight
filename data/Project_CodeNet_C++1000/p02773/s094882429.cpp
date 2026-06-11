#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 5;

int n, mx = 0;
map<string, int> mp;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        string s;
        cin >> s;
        mx = max(mx, ++mp[s]);
    }

    for (auto it : mp) {
        if (it.second == mx) {
            cout << it.first << endl;
        }
    }
}
