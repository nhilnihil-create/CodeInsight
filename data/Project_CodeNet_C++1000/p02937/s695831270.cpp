#include "bits/stdc++.h"
#define rep(i,n) for(int i = 0; i < (n); ++i)
using namespace std;
typedef long long int ll;
typedef pair<ll, ll> P;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    string s, t;
    cin >> s >> t;
    ll n = s.size();
    vector<set<int>> st(26);
    rep(i,26) st[i].insert(100005);
    rep(i,n){
        st[(s[i]-'a')].insert(i);
    }
    ll ans = 0, cur = -1;
    rep(j,t.size()){
        auto idx = st[(t[j]-'a')].lower_bound(cur+1);
        if(*idx == 100005){
            auto idx2 = st[(t[j]-'a')].lower_bound(0);
            if(*idx2 == 100005){
                cout << -1 << endl;
                return 0;
            }
            ans += (n - cur) + *idx2;
            cur = *idx2;
        }
        else{
            ans += *idx - cur;
            cur = *idx;
        }
    }
    cout << ans << endl;
    return 0;
}
