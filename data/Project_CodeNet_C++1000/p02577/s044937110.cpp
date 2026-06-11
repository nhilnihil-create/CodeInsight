#include <bits/stdc++.h>

using namespace std;
typedef long long ll;
const int MOD = 1e9 + 7;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);

    string s;
    cin >> s;
    ll ans = 0;
    for (int i = 0; i < s.length(); ++i) {
        ans += s[i] - '0';
    }
    if (ans % 9 == 0) {
        cout << "Yes" << "\n";
    } else {
        cout << "No" << "\n";
    }
}













