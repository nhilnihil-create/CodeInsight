#include <bits/stdc++.h>
using namespace std;

#define int long long
#define pii pair<int, int>
#define pb push_back

signed main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    string s, t;
    cin >> s >> t;
    int ans = 0;
    for (int i = 0; i < s.size(); i++) {
        ans += (s[i] != t[i]);
    }
    cout << ans << endl;

    return 0;
}

