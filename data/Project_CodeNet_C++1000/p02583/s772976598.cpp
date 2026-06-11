#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    ll N; cin >> N;
    vector<ll> V(N); for(int i = 0; i < N; i++) cin >> V[i];
    ll cnt = 0;
    for(int i = 0; i < N-2; i++){
        for(int j = i+1; j < N-1; j++){
            for(int k = j+1; k < N; k++){
                if(V[i] == V[j] || V[j] == V[k] || V[k] == V[i]) continue;
                ll SUM = V[i]+V[j]+V[k];
                ll MAX = max(V[i], max(V[j], V[k]));
                if(MAX < SUM-MAX) cnt++;

            }
        }
    }
    cout << cnt << endl;
}