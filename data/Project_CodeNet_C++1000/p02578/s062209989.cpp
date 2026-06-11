#include <iostream>
#include <bits/stdc++.h>

#define rep(i,z) for(int i = 0; i<(int)(z); i++)
#define rep1(i,z) for(int i = 1; i<=(int)(z); i++)
 
using namespace std;

typedef long long ll;
const ll MOD=1e9+7;
using pear = pair<int,int>;

int main(){
  ll n; cin>>n;
  vector<ll> a(n);
  rep(i, n) cin>> a[i];
  ll now = a[0], ans = 0;
  for(int i = 1; i < n; i++){
      now = max(now, a[i]);
      ans += now - a[i];
  }
  cout<< ans <<endl;
}