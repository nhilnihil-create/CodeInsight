#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < n; ++i)
#define ll long long
#define P pair<int,int>
#define fast_io ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
const int MOD = 1000000007;
const int INF = 2002002002;
const ll LLINF = 9009009009009009009;
using namespace std;

int main() {
    fast_io
    const int N_ALPHA = 26;
    vector<vector<int>> alp(N_ALPHA);
    string s, t;
    cin >> s >> t;

    rep(i,s.size()) alp[s[i]-'a'].push_back(i+1);

    ll n = s.size(), ans = 0;;
    int f_ind, c_ind = 0;
    for (char c: t) {
        f_ind = c_ind;
        if (alp[c-'a'].empty()) {cout << -1 << endl; return 0;}
        if (alp[c-'a'].end() - upper_bound(alp[c-'a'].begin(), alp[c-'a'].end(), f_ind) == 0) c_ind = alp[c-'a'][0];
        else c_ind = *upper_bound(alp[c-'a'].begin(), alp[c-'a'].end(), f_ind);
        if (f_ind < c_ind) ans += (c_ind - f_ind);
        else ans += (n - f_ind) + c_ind;
    }
    
    cout << ans << endl;
    return 0;
}