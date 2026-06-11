#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

const ll mod = 998244353;

//a^bにおいて、numがa、mulがbである
ll func(ll num, ll mul){
    ll val = 1;
    rep(i, mul){
        val = (val * num) % mod;
    }
    return val;
}

int main(){
    ll N;
    cin >> N;
    vector<ll> d(N);
    vector<ll> dist(N, 0);
    rep(i, N) cin >> d[i];
    ll mx = 0;
    ll ans = 1;
    
    //d[0] != 0であるときは、終了
    if(d[0] != 0){
        cout << 0 << endl;
        return 0;
    }
    //頂点1からの距離をインデックスの値にした配列
    //頂点からの距離がiの頂点が何個あるのかを格納
    rep(i, N) dist[d[i]]++;
    //距離0の頂点がただ1つだけであることを確かめる
    if(dist[0] != 1){
        cout << 0 << endl;
        return 0;
    }
    for(int i = 0; i < N-1; i++){
        if(dist[i] == 0 && dist[i+1] != 0) ans = 0;
        ans = (ans * func(dist[i], dist[i+1])) % mod;
    }
    cout << ans << endl;
    return 0;
}