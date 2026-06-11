#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
// __uint128_t




int main(){
    ll M; cin >> M;
    ll ans = 0, S = 0; 
    vector<ll> D(M), C(M);
    for(int i = 0; i < M; i++){
        cin >> D[i] >> C[i]; 
        ans += C[i]; S += D[i]*C[i]; 
    }
    cout << ans-1+(S-1)/9 <<endl;

}