#include<bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
typedef long long ll;
const ll p = 1e9+7;

ll powmod(ll a, ll b){
    if(b==0) return 1;
    if(b%2==1) return (a*powmod(a,b-1)) % p;
    else{
        ll x = powmod(a,b/2);
        return (x*x) % p;
    }
}

ll combinemod(ll a, ll b){
    ll x=1,y=1;
    for(int i=1;i<=b;i++){
        y = (y*i)%p;
    }
    for(int i=a-b+1;i<=a;i++){
        x = (x*i)%p;
    }

    return (x * powmod(y,p-2)) % p;
}

int main(){
    ll n,k;
    cin >> n >> k;
    for(int i=1;i<=k;i++){
        ll res = (combinemod(n-k+1,i) * combinemod(k-1,i-1)) % p;
        cout << res << endl;
    }
    return 0;
}