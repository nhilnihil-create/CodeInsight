#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
#define rep(i,n) for (int i = 0; i < (n); i++)
const ll mod = 1000000007;

int main() {
    int n; cin >> n;
    string s;
    map<string, ll> mp;
    rep(i,n) {
        cin >> s;
        sort(s.begin(), s.end());
        mp[s]++;
    }
    ll ans = 0;
    for (auto x : mp) {
        ll c = x.second;
        ans += c*(c-1)/2;
    }
    cout << ans << endl;
    return 0;
}
