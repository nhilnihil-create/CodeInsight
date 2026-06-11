#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {

    int n; cin >> n;
    string s, t; cin >> s >> t;
    string ans = "";
    for (int i = 0; i < n; i++) {
        ans += s[i];
        ans += t[i];
    }
    cout << ans << endl;
    return 0;
}