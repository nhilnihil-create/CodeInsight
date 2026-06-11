#include<bits/stdc++.h>
#define rep(i,N) for(int i=0;i<(N);i++)
#define FOR(i,a,b) for(int i=(a);i<(b);i++)
using namespace std;
const long long MOD = 1e9 + 7;
const long long INF = 1e12;
const int inf = 1e9;
const int mod = 1e9+7;
typedef long long ll;
typedef pair<ll,int> P;
typedef set<int> S;
// 繰り返し二乗法 O(log n)
ll f[3000000] = {0}; // f(n) = (n!) % mod
//階乗テーブルの初期化を忘れない
//f[0] = f[1] = 1;
//for(int i=2; i<=w+h-2; ++i) f[i] = (i * f[i-1]) % mod;
ll mod_pow(ll x, ll n){
    ll res = 1LL;
    while(n > 0){
        if(n & 1) res = res * x % mod;
        x = x*x % mod;
        n >>= 1;
    }
    return res;
}
ll mod_inv(ll x){
    return mod_pow(x, mod-2) % mod;
}
// nCr % mod
ll comb(int n, int r){
    return (((f[n] * mod_inv(f[r])) % mod) * mod_inv(f[n-r])) % mod;
}
int main(){

    int x,y;
    cin >> x >> y;
    if((x+y)%3!=0) cout<<0<<endl;
    else{
        int n1 = (2*x-y)/3;
        int n2 = (2*y-x)/3;
        if(n1<0 || n2<0){
            cout<<0<<endl;
            return 0;
        }else{
            f[0] = f[1] = 1;
            //cout<< n1 <<" "<< n2 << endl;
            for(int i=2; i<=n1+n2+1000; ++i) f[i] = (i * f[i-1]) % mod;
            cout<<comb(n1+n2,n1)<<endl;
        }
    }

    return 0;
}