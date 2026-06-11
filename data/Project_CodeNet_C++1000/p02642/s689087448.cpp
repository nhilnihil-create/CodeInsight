#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MAX=2001000;
int main(){
  ll N;
  cin>>N;
  vector<int>A(N);
  for(ll i=0;i<N;i++)cin>>A[i];
  vector<int>M(MAX,0);
  for(auto a:A){
    if(M[a]!=0){
      M[a]=2;continue;
    }
    for(ll i=a;i<=MAX;i+=a)M[i]++;
  }
  ll ans=0;
  for(auto a:A){
    if(M[a]==1)ans++;
  }
  cout<<ans<<endl;
}
