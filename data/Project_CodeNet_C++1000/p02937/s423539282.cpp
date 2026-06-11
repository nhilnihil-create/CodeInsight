#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double pi=3.141592653589793;
typedef unsigned long long ull;
typedef long double ldouble;
const ll INF=1e18;
#define rep(i, n) for(ll i = 0; i < (ll)(n); i++)
#define rep2(i, s, n) for (ll i = (s); i < (ll)(n); i++)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }


int main(){
    string s, t;
    cin >> s >> t;
    ll count = 0, n = s.length(), m = t.length();
    vector<vector<ll> > a(26);
    rep(i, n) {
        a[s[i] - 'a'].push_back(i+1);
    }
    ll index = 0;
    rep(i, m) {
        if(a[t[i] - 'a'].size() == 0) {
            cout << -1 << endl;
            return 0;
        }
        else {
            // -------------- 二分探索 --------------------
            // 解の存在範囲を初期化
            ll ti = t[i] - 'a';
            // -------------- 標準ライブラリ --------------------
            auto position = upper_bound(a[ti].begin(), a[ti].end(), index);
            ll low_idx = distance(a[ti].begin(), position);
            //cout << (char) (ti + 'a') << " :" << a[ti][low_idx] << " index:" << index << " low_idx:" << low_idx << endl;
            if(low_idx == a[ti].size()) {
                count++;
                index = a[ti][0];
            }
            else {
                index = a[ti][low_idx];
            }
        }
    }
    cout << count * n + index << endl;
}