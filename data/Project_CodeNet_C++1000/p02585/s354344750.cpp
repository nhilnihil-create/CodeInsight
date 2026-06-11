#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
 
int main() {
    int N, K;
    cin >> N >> K;
    vector<int> P(N), C(N);
    rep(i, N) cin >> P.at(i);
    rep(i, N) cin >> C.at(i);
    rep(i ,N) P.at(i) --;
    ll ans = -1e18;
    rep(si, N){
        int x = si;
        vector<int> s;
        ll total = 0;
        while(1){
            x = P.at(x);
            s.push_back(C.at(x));
            total += C.at(x);
            if (x == si) break;
        }
        int l = s.size();
        ll t = 0;
        rep(i, l){
            t += s.at(i);
            if(i >= K) break;
            ll now = t;
            if(total > 0){
                ll roop = (K - (i + 1)) / l;
                now += roop * total;
            }
            ans = max(ans, now);
        }
    }
    cout << ans << endl;
}