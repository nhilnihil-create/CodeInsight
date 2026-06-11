#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll LINF = 1e18;
const int INF = 1e9;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)

ll mod = 1e9+7;
//a+2b=X,2a+b=Y => b=(X-a)/2 and Y-2a  

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
    ll X,Y; cin>>X>>Y;
    ll N = max(X,Y/2);
    ll a,b=-1;
    rep(i,N+1){
        if((X-i)/2.0 == Y-2*i){
            a=i;
            b=Y-2*i;
        }
    }
    if(b==-1){
        cout<<0<<endl;
        return 0;
    }
    ll ans=1;
    rep(i,a){
        ans*=(a+b-i);
        ans%=mod;
    } 
    ll c=1;
    rep(i,a){
        c*=(a-i);
        c%=mod;
    }
    cout<<(ans*modinv(c,mod))%mod<<endl;
    return 0;
}