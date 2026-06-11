#include <bits/stdc++.h>
using namespace std;
using ll = long long;
#define rep(i,n) for(ll i=0;i<ll(n);i++)

int main() {
    ll n;
    cin >> n;
    map<string, int>mp;
    int m = 0;
    rep(i, n){
        string s;
        cin >> s;
        mp[s]++;
        m = max(m, mp[s]);
    }
    for (auto x : mp) {
        if (x.second == m) {
            cout << x.first << endl;
        }
    }
    return 0;
}
