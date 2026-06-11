#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); i++)
using ll = long long;
using namespace std;
const ll mod = 1e9 + 7;


ll powmod(ll x,ll y){
   ll res=1;
   for(ll i=0;i<y;i++){
      res=res*x%mod;
   }
   return res;
}


int main()
{
   ll n;
   cin >> n;

   ll a;
   a=powmod(10,n)+powmod(8,n)-powmod(9,n)-powmod(9,n);
a %= mod;
a = (a+mod)%mod;

   cout << a  << endl;
}