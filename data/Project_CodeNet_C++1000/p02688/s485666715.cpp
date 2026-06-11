#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,K;
  cin>>N>>K;
vector<bool> vec(N,false);
  for (ll i=0;i<K;i++) {
ll d;
    cin>>d;
    for(ll i=0;i<d;i++) {
ll A;
      cin>>A;
      vec[A-1]=true;
    }
  }
  
  ll count=0;
  for(auto x:vec) {
if(!x) {
count++;
}
  }
  
  cout<<count<<endl;
}