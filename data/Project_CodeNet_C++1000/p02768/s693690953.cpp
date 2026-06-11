#include<bits/stdc++.h>
using namespace std;

using ll = long long;
const ll p = 1000000007;

ll power(ll x, ll y,ll p){
    ll res = 1;    
  
    x = x % p;  
  
    while (y > 0){  
        if (y & 1)  
            res = (res*x) % p;  
  
        y = y>>1; 
        x = (x*x) % p;  
    }  
    return (res%p);  
} 

ll modInverse(ll n,ll p){
    return power(n,p-2,p);
}
ll nCr(ll n, ll k)  {  
    ll ans = 1;   
    if(k<0 || k>n){
        return 0;
    }
    k = min(k,n-k);
    for (ll i = 1; i <= k; ++i){  
        ans = ((ans*modInverse(i,p))%p * (n+1-i))%p;
    }  
  
    return ans;  
} 

int main(){
    ll n,a,b;
    cin >> n >> a >> b;

    ll sum = power(2,n,p)-1;
    //cout << (binomialCoeff(n,a))%m << " " << (binomialCoeff(n,b))%m << "\n";
    sum = ((sum - (nCr(n,a))-nCr(n,b))%p + p)%p;

    cout << (sum%p) << "\n";
    return 0;
}