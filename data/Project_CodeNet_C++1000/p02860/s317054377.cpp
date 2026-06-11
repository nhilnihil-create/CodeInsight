#include <bits/stdc++.h>
using namespace std;
using ll = long long;
const ll INF = 1LL << 60;

int main() {
    int n;
    string s;
    cin >> n >> s;
    string ans = "Yes";
    if (n % 2) {
        ans = "No";
    }
    for (int i = 0; i * 2 < n; i++) {
        if (s[i] != s[n / 2 + i]) {
            ans = "No";
            break;
        }
    }
    cout << ans << endl;
    return 0;
}
