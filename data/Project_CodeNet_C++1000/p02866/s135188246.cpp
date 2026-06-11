#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define call(var) cout<<#var<<"="<<var<<endl;
using ll=long long;
using vi = vector<int>;
using vl = vector<ll>;
using Graph = vector<vi>;
using P = pair<int,int>;
const int MOD=998244353;
const int INF=(int)1e9;
const ll LINF=(ll)1e18;
template<class t,class u> void chmax(t&a,u b){if(a<b)a=b;}
template<class t,class u> void chmin(t&a,u b){if(b<a)a=b;}

ll pow_mod(ll n,ll p,ll m){
    ll res = 1;
    while(p>0){
        if(p%2==1) res = (res * n) % m;
        n = (n * n) % m;
        p /= 2;
    }
    return res;
}

int main(){
    int n;
    cin >> n;
    map<int,int> m;
    ll ans = 1;
    rep(i,n){
        int a;
        cin >> a;
        m[a]++;
        if(i==0 && a!=0) ans = 0;
        if(i!=0 && a==0) ans = 0;
    }
    
    for(int i=0;i<m.size()-1;i++){
        ll t = pow_mod(m[i],m[i+1],MOD);
        ans = (ans * t) % MOD;
    }
    cout << ans << endl;
}