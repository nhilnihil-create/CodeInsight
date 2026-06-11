#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N,M;
  cin>>N>>M;
  vector<bool> vec(N,false);
  vector<ll> pena(N,0);
  ll pe=0;
  ll ans=0;
  
  for(ll i=0;i<M;i++) {
ll p;
    string S;
    cin>>p>>S;
    if(vec[p-1]) {
continue;
    }
    if(S=="AC") {
ans++;
      vec[p-1]=true;
      pe+=pena[p-1];
    }
    
    else {
pena[p-1]++;
    }
  }
  
  
cout<<ans<<" "<<pe<<endl;
}