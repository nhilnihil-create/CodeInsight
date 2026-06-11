#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    ll N, K; cin >> N >> K;
    vector<ll> P(N), C(N);
    vector<vector<ll>> V;
    map<ll, ll> M, W; 
    for(int i = 0; i < N; i++) {
        cin >> P[i]; P[i]--;
        W[i] = P[i];
    }
    for(int i = 0; i < N; i++) cin >> C[i];
    vector<bool> vis(N+1, false);
    for(int i = 0; i < N; i++){
        vector<ll> temp;
        ll idx = i;
        while(!vis[idx]){
            vis[idx] = true;
            temp.push_back(C[idx]);
            idx = W[idx];
        }
        if(temp.size() != 0)V.push_back(temp);
    }
    
    ll ans_ = -INF;
    for(auto v : V){
        vector<ll> U = v;
        ll n = v.size();
        for(int i = 0; i < n; i++) U.push_back(U[i]);
        ll ans = -INF;
        
        unordered_map<ll, ll> MP;
        for(int i = 1; i <= n; i++){
            ll cnt = 0;
            for(int j = 0; j < i; j++) cnt += U[j];
            MP[i] = cnt;
            for(int j = i; j < 2*n; j++){
                cnt += U[j];
                cnt -= U[j-i];
                MP[i] = max(cnt, MP[i]);
            }
        }

        ll MAX1 = -INF; for(int i = 1; i <= n; i++) MAX1 = max(MAX1, MP[i]);
        ll MAX2 = -INF; for(int i = 1; i <= K%n; i++) MAX2 = max(MAX2, MP[i]);
        if(n <= K){
            ll SUM = 0;
            for(int i = 0; i < n; i++) SUM += U[i];
            SUM = max(0LL, SUM);
            ans = max((K/n-1)*SUM + MAX1 , (K/n)*SUM + MAX2);
        }
        else {
            ans = MAX2;
        }
        ans_ = max(ans, ans_);
    }
    cout << ans_ << endl;
    

}