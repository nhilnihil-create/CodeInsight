#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    ll N, K; cin >> N >> K;

    vector<ll> V(N); for(int i = 0; i < N; i++) cin >> V[i];

    ll Min = 1; 
    ll Max = 1e9+1;
    ll Mid;
    ll ans = 1e9+1;
    while(Min < Max){
        Mid = (Min + Max) / 2;
        ll cnt = 0;
        for(int i = 0; i < N; i++){
            cnt += (V[i] + Mid -1) / Mid-1;
        }
        if(cnt <= K) {
            Max = Mid;
            ans = min(ans, Mid);
        }
        else Min = Mid+1;
        //cout << cnt << " "  << K << " " << Mid << endl;
    }
    cout << ans << endl;
}