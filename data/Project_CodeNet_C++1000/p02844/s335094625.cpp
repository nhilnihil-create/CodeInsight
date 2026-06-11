#pragma GCC optimize("O3")
#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using vl = vector<ll>;
using vc = vector<char>;
using vvl = vector<vector<ll>>;
using vvc = vector<vector<char>>;

#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define repd(i,n) for(ll i = n - 1; i >= 0; i--)
#define all(x) x.begin(), x.end()

ll n, k, m, M = 1e9 + 7;

int main() {
cin.tie(0);
ios::sync_with_stdio(false);

string s;
cin >> n >> s;

ll num = 0;
for(int pass = 1000; pass < 2000; pass++) {
    string t = to_string(pass);
    t.erase(t.begin());
    
    int idx = 0;
    rep(i, n) {
        if(s[i] == t[idx]) idx++;
        if(idx == 3) {
            num++;
            break;
        }
    }
}

cout << num << endl;
}
