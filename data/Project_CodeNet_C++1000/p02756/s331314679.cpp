#include <bits/stdc++.h>
using namespace std;
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int64_t i = 0; i < (int64_t)(n); i++)
using vi = vector<int64_t>;
using vvi = vector<vi>;
using ll = int64_t;
using P = pair<ll,ll>;
ll INF = 1000000007;
// ll INF = 9223372036854775807;
// ll INF = 998244353;

int main() {
    // fasten cin
    cin.tie(0);
    ios::sync_with_stdio(false);
    // implement
    string s;
    cin >> s;
    ll q;
    cin >> q;
    bool isRev = false;
    rep(i,q){
        ll t;
        cin >> t;
        if(t==1) isRev = !isRev;
        if(t==2){
            ll f;
            string c;
            cin >> f >> c;
            if(f==1) s.insert(isRev?s.size():0,c);
            if(f==2) s.insert(isRev?0:s.size(),c);
        }
    }
    if(isRev) reverse(s.begin(), s.end());
    cout << s << endl;
}