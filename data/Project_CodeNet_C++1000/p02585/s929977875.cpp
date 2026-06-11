#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<int, int>;

#define rep(i,n) for (int i = 0; i < (n); ++i)


void solve(long long N, long long K, std::vector<long long> P, std::vector<long long> C){
    ll ans = -1e18;
    rep(i,N){
        ll score = 0;
        vector<ll> mp(N+1, -1);
        ll p = P[i] - 1;
        ll c = C[p];
        ll cnt = 0;
        rep(j,N){
            if(mp[p] != -1 || j >= K) break;
            cnt++;
            mp[p] = cnt;
            p = P[p] - 1;
            score += c;
            c = C[p];
            ans = max(ans, score);
        }
        if(mp[p] != -1 && score > 0){
            ll l = mp[i];
            p = P[i] - 1;
            c = C[p];
            ll tot = 0;
            rep(j,l){
                tot += c;
                p = P[p] - 1;
                c = C[p];
                ll e = (K - (j + 1)) / l;
                ll t = tot;
                t += score * e;
                ans = max(ans, t);
            }
        }
        
    }
    cout << ans << endl;

}

int main(){
    long long N;
    scanf("%lld",&N);
    long long K;
    scanf("%lld",&K);
    std::vector<long long> P(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&P[i]);
    }
    std::vector<long long> C(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%lld",&C[i]);
    }
    solve(N, K, std::move(P), std::move(C));
    return 0;
}
