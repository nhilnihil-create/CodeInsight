#include <bits/stdc++.h>
using namespace std;

int32_t main() {
    int sm = 0;
    string s; cin >> s;
    for (auto el : s) {
        sm += el - '0';
        sm %= 9;
    }
    if (sm) cout << "No\n";
    else cout << "Yes\n";

    return 0;
}
