#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using Map = map<string,ll>;
using vl = vector<ll>;
using vvl = vector<vector<ll>>;
ll MAX=2001;
ll MOD=1000000007;
vector<ll> F(MAX,1);
 
void fact(){
    for(ll i=1;i<MAX;i++){
    F[i]=F[i-1]*i%MOD;
    }
return;
}


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

long long comb(long long a, long long b){
    return (((F[a]*modinv(F[b],MOD))%MOD)*modinv(F[a-b],MOD))%MOD;
}



int main(){
    ll N;
    cin >> N;
    ll K;
    cin >> K;
    fact();
    for(ll i=1;i<=K;i++){
        if(N-K<i-1)cout<<0<<endl;
        else{
            cout<<(comb(K-1,i-1)*comb(N-K+1,i))%MOD<<endl;
        }
    ;}

    return 0;
}
