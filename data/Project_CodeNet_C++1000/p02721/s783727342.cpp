//#include<bits/stdc++.h>
#include<iostream>
#include<iomanip>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<string>
#include<numeric>
#include<vector>
#include<set>
#include<map>
#include<unordered_map>
#include<stack>
#include<queue>
#include<list>
using namespace std;

typedef long long ll;

#define MOD 1000000007

class Comb{
public:
  ll *fac,*finv,*inv;
  Comb(){
    fac = new ll[1000001];
    finv = new ll[1000001];
    inv = new ll[1000001];
    fac[0] = 1;
    for(int i=1;i<1000001;i++){
      fac[i] = i*fac[i-1];
      fac[i] %= MOD;
    }
    inv[1] = 1;
    for(int i=2;i<1000001;i++){
      inv[i] = MOD-inv[MOD%i]*(MOD/i)%MOD;
    }
    finv[0] = 1;
    for(int i=1;i<1000001;i++){
      finv[i] = inv[i]*finv[i-1];
      finv[i] %= MOD;
    }
  }
  ll calc(ll n,ll k){
    ll c = fac[n];
    c *= finv[k];c %= MOD;
    c *= finv[n-k];c %= MOD;
    return c;
  }
};

ll powmod(ll x,ll n){
  if(n == 0) return 1;
  if(n == 1) return x%MOD;
  if(n%2 == 0){
    ll temp = powmod(x,n/2);
    return (temp*temp)%MOD;
  }
  else{
    ll temp = powmod(x,n/2);
    temp = (temp*temp)%MOD;
    return (temp*x)%MOD;
  }

}

int main(){
   int n,k,c;
   string s;
   cin >> n >> k >> c;
   cin >> s;
   int a[k+1],b[k+1];
   int now = 0;
   int lock = -1;
   int ind = 0;
   while(now != k){
     if(s[ind] == 'x'){
       ind++;
       continue;
     }
     if(lock < ind){
       now++;
       lock = ind+c;
       a[now] = ind;
     }
     ind++;
   }
   now = 0;
   lock = n+1;
   ind = n-1;
   while(now != k){
     if(s[ind] == 'x'){
       ind--;
       continue;
     }
     if(ind < lock){
       now++;
       lock = ind-c;
       b[now] = ind;
     }
     ind--;
   }

   for(int i=1;i<k+1;i++){
     if(a[i] == b[k+1-i]) cout << a[i]+1 << endl;
   }
   return 0;
}
