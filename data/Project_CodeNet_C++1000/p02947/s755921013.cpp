#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;
#define chmax(x,y) x = max(x,y);

int main() {
    int n;
    cin >> n;
    map<string, ll> mp;
    rep(i,n) {
        string s;
        cin >> s;
        sort(s.begin(), s.end());
        mp[s]++;
    } 
    ll ans = 0;
    for (auto x : mp) {
        ll y = x.second;
        ans += y*(y-1)/2;
    }
    cout << ans << endl;
    return 0;
}