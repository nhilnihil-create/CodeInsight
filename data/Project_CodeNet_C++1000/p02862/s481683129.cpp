/**
*    author:  souzai32
*    created: 23.08.2020 15:20:41
**/

#include <bits/stdc++.h>
#define all(x) (x).begin(),(x).end()
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
ll mod=1000000007;
using namespace std;

bool Factorial(ll x, vector<ll>&f){
    f[0]=1;
    for(int i=1; i<=x; i++){
        f[i]=(f[i-1]*i)%mod;
    }
    return true;
}

int main() {

    int x,y,n;
    cin >> x >> y;
    if(x>y) swap(x,y);

    // vector<ll> f(x+1);
    // Factorial(x,f);

    // for(int i=0; i<=x; i++){
    //     cout << f[i] << endl;       
    // }

    // for(int i=0; i<=n; i++) cout << f[i] << endl;

    ll ans=0;
    if((x+y)%3==0){
        if(2*x>=y && x<=2*y){
            n=(x+y)/3;
            vector<ll> f(n+1);
            Factorial(n,f);
            ans=f[n];
            ll bit=mod-2;
            ll k=f[x-n];
            while(bit>0){
                if((bit&1)==1) ans=(ans*k)%mod;
                k=(k*k)%mod;
                bit>>=1;
            }
            bit=mod-2;
            k=f[2*n-x];
            while(bit>0){
                if((bit&1)==1) ans=(ans*k)%mod;
                k=(k*k)%mod;
                bit>>=1;
            }
        }
    }

    cout << ans << endl;

    return 0;
}