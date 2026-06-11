#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    ll N, M, K; cin >> N >> M >> K;
    vector<ll> A(N), B(M);
    for(int i = 0; i < N; i++) cin >> A[i];
    for(int i = 0; i < M; i++) cin >> B[i];
    ll ans = 0;
    for(int i = 1; i < N; i++) A[i] += A[i-1];
    for(int i = 1; i < M; i++) B[i] += B[i-1];
    int ia = 0, ib = M-1;

    
    for(int i = 0; i < M; i++) if(B[i] <= K) ans = i+1;

    for(;ia < N; ia++){
        int na = ia+1;
        ll ta = A[ia];
        if(K < ta) continue;

        //ll tb = max((ll)0, K-ta);
        ll tb = K -ta;
        while(ib >= 0 && tb < B[ib])ib--;
        ll nb = ib+1;

        ans = max(ans, na+nb);
    } 
    cout << ans << endl;

}