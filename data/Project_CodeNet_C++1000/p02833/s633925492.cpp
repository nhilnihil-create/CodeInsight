#include <iostream>
#include <bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<int(n);i++)
#define rep1(i,n) for(int i=1;i<int(n);i++)
#define all(a) (a).begin(),(a).end()
using ll = long long;
using ld = long double;
using Pint = pair<int,int>;
const ll mod = 1e9+7;

ll g1(ll n, ll p){
  if(n==0) return 0;
  return n/p + g1(n/p, p);
}

ll g2(ll n, ll p){
  if(n&1) return 0;
  if(p==2) {
    return g1(n/2, p) + n/2;
  }
  return g1(n/2, p);
}

int main(){
  ll n;
  cin>>n;

  ll ans=g2(n,5);

  cout<<ans<<endl;

  return 0;
}