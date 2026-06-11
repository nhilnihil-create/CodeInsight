#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const static ll INF = 1e15;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
// __uint128_t
const ll MOD = 1e9+7;

int main(){
    ll N, cnt = 0; cin >> N;
    vector<ll> V(N); for(int i = 0; i < N; i++) cin >> V[i];
    for(int i = 0; i < N; i++)
        if((i+1)%2==1 && V[i]%2==1) cnt++;
    cout << cnt << endl;
} 