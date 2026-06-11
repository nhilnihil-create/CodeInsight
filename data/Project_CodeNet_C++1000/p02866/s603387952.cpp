#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
using namespace std;
typedef long long ll;
int INF = (1LL << 30) - 1;
int MOD = 998244353;
ll powmod(ll x,ll n){
    if(n == 0)return 1;
    ll ans = powmod(x*x%MOD,n/2);
    if(n % 2)ans = ans * x % MOD;
    return ans;
}

vector<int> compress(map<int,ll> mp){
    auto itr = mp.end();
    itr--;
    int size = (itr->first) + 1;
    vector<int> vec(size);
    for(auto p:mp){
        vec[p.first] = p.second;
    }
    return vec;
}
main(){
    int N;
    cin >> N;
    vector<int> V(N);
    rep(i,0,N)cin >> V[i];
    map<int,ll> mp;
    rep(i,0,N)mp[V[i]]++;
    auto vec = compress(mp);
    /*
    for(auto i:vec){
        cout << i << " ";
    }cout << endl;
    */
    if(vec[0] != 1 || V[0] != 0){
        cout << 0 << endl;
        return 0;
    }

    ll ans = 1;
    rep(i,1,vec.size()){
        int n = vec[i-1], r = vec[i];
        ll num = powmod(n, r);
        //cout << num << endl;
        ans = ans % MOD * num % MOD;
    }
    cout << ans << endl;

}