#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
int main(){
  ll N,ans=0;
  cin>>N;
  vector<ll> vec(N);
  for(ll i=0;i<N;i++){
    cin>>vec.at(i);
  }
  for(ll i=0;i<N-1;i++){
    for(ll j=i+1;j<N;j++){
      ans+=vec.at(i)*vec.at(j);
    }
  }
  cout<<ans<<endl;
} 