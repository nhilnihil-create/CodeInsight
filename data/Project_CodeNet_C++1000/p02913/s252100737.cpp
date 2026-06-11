#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define pb push_back
#define F first
#define S second
const int mod = 1e9 + 7, A = 1e3 + 2;
int n;
string s;
bool valid(int len) {
    int p2 = len;
    string t = s.substr(0, len);
    map<string, vector<int>> mop;
    mop[t].pb(p2);
    while(p2 < n) {
        t.erase(t.begin()), t.pb(s[p2++]);
        mop[t].pb(p2);
    }
    for (auto i : mop) {
        int mn = i.S[0], mx = i.S[0];
        for (auto j : i.S)
            mn = min(mn, j), mx = max(mx, j);
        if (mx - mn >= len)
            return 1;
    }
    return 0;
}
int main() {
    ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0);
    cin >> n >> s;
    int ans = 0, low = 1, high = n / 2, mid;
    while(low <= high) {
        mid = (low + high) / 2;
        if (valid(mid))
            low = mid + 1, ans = mid;
        else
            high = mid - 1;
    }
    cout << ans;
    return 0;
}
