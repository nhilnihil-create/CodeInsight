#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n,m;
  cin >> n >> m;

  multiset<ll> a;
  rep(i,n){
    ll g;
    cin >> g;
    a.insert(g);
  }

  rep(i,m){
    ll d;
    d =  *a.rbegin();
    a.erase(a.find(d));
    d = d/2;
    a.insert(d);
  }

  ll ans=0;
  rep(i,n){
    ll d = *a.rbegin();
    a.erase(a.find(d));
    ans+=d;
  }

  cout << ans;
  
}