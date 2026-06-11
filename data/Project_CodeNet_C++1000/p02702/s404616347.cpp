#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

const int mod = 2019;

int main() {
    string s;
    cin >> s;
    int n = s.size();
    reverse(s.begin(),s.end());
    int x = 1, tot = 0;
    vector<int> cnt(mod);
    ll ans = 0;
    rep(i,n) {
        cnt[tot]++;
        tot += (s[i]-'0')*x;
        tot %= mod;
        ans += cnt[tot];
        x = x*10%mod;
    }
    cout << ans << endl;
    return 0;
}