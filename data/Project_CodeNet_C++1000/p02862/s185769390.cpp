#include<bits/stdc++.h>
using namespace std;
using lli = long long;
#define rep(i,n) for(int i=0;i<n;i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

#define N 5e6
const lli mod = 1e9+7;
lli x, y;
vector<lli> inv(N);
vector<lli> fact(N);
vector<lli> fact_inv(N);

void setinv(){
    inv[1] = 1;
    for(int i = 2; i < N; i++){
        inv[i] = mod-((mod/i)*inv[mod%i]%mod);
    }
}
void setfact(){
    fact[0] = fact[1] = 1;
    for(int i = 2; i < N; i++){
        fact[i] = i*fact[i-1]%mod;
    }
}
void setfact_inv(){
    fact_inv[0] = fact_inv[1] = 1;
    for(int i = 2; i < N; i++){
        fact_inv[i] = inv[i]*fact_inv[i-1]%mod;
    }
}
lli comb(lli n, lli k){
    lli ret = (fact[n]*fact_inv[k]%mod)*fact_inv[n-k]%mod;
    return ret;
}

int main(void){
    setinv();
    setfact();
    setfact_inv();
    cin >> x >> y;
    lli a = 2*y-x;
    lli b = 2*x-y;
    if(a < 0 || b < 0 || a%3 != 0 || b%3 != 0){
        cout << 0 << endl;
        return 0;
    }
    a/=3;
    b/=3;
    cout << comb(a+b, a) << endl;
    return 0;
}
