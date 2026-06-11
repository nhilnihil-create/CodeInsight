#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
ll X;
  cin>>X;
  ll N=1000000;
  vector<bool> vec(N,false);
  vector<ll> S(0);
  for(ll i=2;i<=N;i++) {
    if(vec[i]) {
continue;
    }
    S.push_back(i);
    ll count=1;
    while(count*i<=N) {
vec[i*count]=true;
      count++;
      
    }
  }
  
 ll i=lower_bound(all(S),X)-S.begin();
  cout<<S[i]<<endl;
}

  
  
  
  
  
  
  