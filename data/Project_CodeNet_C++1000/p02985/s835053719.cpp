#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll MOD = 1e9+7;


int main(){
    ll N, K; cin >> N >> K;
    vector<vector<ll>> V(N);
    for(int i = 0; i < N-1; i++){
        ll a, b; cin >> a >> b; a--;b--;
        V[a].push_back(b);
        V[b].push_back(a);
    }
    ll ans = K;
    ans %= MOD;
    queue<ll> Q;
    vector<bool> grid(N); grid[0] = true;
    Q.push(0);
    bool flag = true;
    while(!Q.empty()){
        ll x = Q.front(); Q.pop();
        ll k;
        if(flag) {k = K-1; flag = false;}
        else k = K-2;
        for(auto v : V[x]){
            if(!grid[v]) {
                grid[v] = true;
                Q.push(v);
                ans*=k;
                ans%=MOD;
                k--;
            }
        }

    }
    cout << ans << endl;

}
