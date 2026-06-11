#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;

ll MOD=1000000007;

// mod. m での a の逆元 a^{-1} を計算する
//ただしmとaが互いにその時のみ
long long modinv(long long a, long long m) {
    long long b = m, u = 1, v = 0;
    while (b) {
        long long t = a / b;
        a -= t * b; swap(a, b);
        u -= t * v; swap(u, v);
    }
    u %= m;
    if (u < 0) u += m;
    return u;
}

int main(){
    ll N;
    cin >> N;
    ll K;
    cin >> K;
    for(ll i=1;i<=K;i++){
        if(N-K<i-1)cout<<0<<endl;
        else{
            ll x=1,y=1,z=1,w=1;
            for(ll j=0;j<i-1;j++){
                x*=K-1-j;
                x%=MOD
            ;}
            for(ll j=1;j<=i-1;j++){
                y*=j;
                y%=MOD
            ;}
            for(ll j=0;j<i;j++){
                z*=N-K+1-j;
                z%=MOD;
            ;}
            for(ll j=0;j<i;j++){
                w*=(j+1);
                w%=MOD
            ;}
            ll qq=(x*modinv(y,MOD))%MOD;
            ll pp=(z*modinv(w,MOD))%MOD;
            cout<<(qq*pp)%MOD<<endl;
        }
    ;}

    return 0;
}
