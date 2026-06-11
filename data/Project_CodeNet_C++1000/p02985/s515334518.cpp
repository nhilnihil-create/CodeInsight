#include <bits/stdc++.h>
using namespace std;
using ll=long long;
ll N,K;
vector<vector<ll>> tree;
const ll MOD = ll(1e9)+7;

ll dfs(int t,int p){
    ll retVal  = 1;
    ll initK = K-2;
    if(p==-1){
        initK = K-1;
    }
    for(ll child:tree[t]){
        if(child ==p){
            continue;
        }
        retVal *= ((initK*dfs(child,t))%MOD);
        retVal %=MOD;
        --initK;
    }
    return retVal;
}

int main() {
   
    cin >> N >> K;
    tree.resize(N);
    for(int i=0;i<N-1;i++){
        ll a,b;
        cin >> a >> b;
        --a;--b;
        tree[a].push_back(b);
        tree[b].push_back(a);
    }
    ll ans  = dfs(0,-1) * K;
    cout << ans%MOD << endl;

    return 0;
}