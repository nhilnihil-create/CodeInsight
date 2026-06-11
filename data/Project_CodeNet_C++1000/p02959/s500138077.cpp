#include <bits/stdc++.h>
using namespace std;
#include<cstdlib>

#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;

int main(){
  int n;
  cin >> n;

  vector<ll> a(n+1);
  vector<ll> b(n);

  rep(i, n+1) cin >> a.at(i);
  rep(i, n) cin >> b.at(i);

  ll mon=0;
  rep(i,n){
    ll first = min(a.at(i), b.at(i));
    ll second = min(a.at(i+1), b.at(i)-first);
    a.at(i+1) -= second;

    mon += (first+second);
    
  }

  cout << mon;
}
