#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for (int i = 0; i < (n); ++i)
typedef long long ll; //10^19 < 9223372036854775807
typedef unsigned long long ull; //10^20 < 18446744073709551615


int main(){
  int n,k; cin>>n>>k;
  vector<ll> h(n);
  rep(i,n) cin>>h.at(i);
  ll ans=0;
  
  sort(h.begin(), h.end());
  
  rep(i,n-k){
    ans+=h.at(i);
  }
  cout<<ans;

}