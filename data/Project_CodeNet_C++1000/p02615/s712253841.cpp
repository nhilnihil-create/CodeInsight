#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
//__uint128_t
const ll MOD = 1e9+7;

int main(){
    ll N; cin >> N;
    vector<ll> V(N); for(int i = 0; i < N; i++) cin >> V[i];
    sort(V.begin(), V.end());
    ll ans = V[N-1];
    ll cnt = 1;

    for(int i = N-2; i >= 0; i--){
        if(cnt == N-1) break;
        ans += V[i];
        cnt++;
        if(cnt == N-1) break;
        ans += V[i];
        cnt++;
        if(cnt == N-1) break;
    }
    cout << ans << endl;

}
