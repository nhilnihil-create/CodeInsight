#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
using ll = long long;
using P = pair<int,int>;

int main() {
    int N;
    string S;
    cin >> N;
    map<string, ll> mp;
    rep(i,N) {
        cin >> S;
        sort(S.begin(), S.end());
        ++mp[S];
    }
    ll ans = 0;
    for (auto x : mp) {
        if (x.second >= 2) {
            ans += x.second * (x.second - 1) / 2;
        }
    }
    cout << ans << endl;
}
