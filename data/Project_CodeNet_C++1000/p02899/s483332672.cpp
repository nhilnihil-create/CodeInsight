#include <bits/stdc++.h>
using namespace std;
using ll =long long;
#define all(v) v.begin(),v.end()
 
int main() {
  ll N;
  cin>>N;
  vector<pair<ll,ll>> vec(N);
  for(ll i=0;i<N;i++) {
ll A;
    cin>>A;
    vec[i]=make_pair(A,i+1);
  }
  sort(all(vec));
  for(ll i=0;i<N;i++) {
cout<<vec[i].second<<" ";
  }
  cout<<endl;
}
  
  
