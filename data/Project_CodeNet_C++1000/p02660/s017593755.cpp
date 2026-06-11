#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <vector>
#define rep(i,n) for(int i=0; i<(n); i++)
using ll = long long;
using namespace std;

int main(){
  ll n,ans=0;
  cin >> n;
  vector<pair<ll, ll> > p;
  for(ll i=2; (i*i)<=n; i++){
    ll count = 0;
    if(n%i==0){
      while(n%i == 0){
        n /= i;
        count++;
      }
      p.push_back(pair(i,count));
    }
  }
  if(n > 1){
    p.push_back(pair(n,1));
  }
  
  for(auto& i: p){
    ll j=1;
    while(i.second >= j){
      i.second -= j;
      ans++;
      j++;
    }
  }
  
  cout << ans << endl;
  
  return 0;
}
