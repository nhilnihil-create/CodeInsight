#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (n); i++)
#define ALL(v) (v).begin(), (v).end()
using ll = long long;
using P = pair<int, int>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e18;
constexpr long long MOD = 1e9 + 7;

signed main() {
    int n;
    cin >> n;
    int m = 1 << n;
    ll s[m];
    rep(i, m) {
        cin >> s[i];
        s[i] *= -1;
    }
    multiset<ll> C(s, s + m), P;
    P.emplace(*C.begin());
    C.erase(C.begin());
    rep(i, n) {
        multiset<ll> T;
        for(auto p : P){
            auto itr = C.upper_bound(p);
            if(itr == C.end()){
                cout << "No" << endl;
                return 0;
            }
            C.erase(itr);
            T.emplace(*itr);
        }
        for(auto t : T){
            P.emplace(t);
        }
    }
    cout << "Yes" << endl;
    return 0;
}