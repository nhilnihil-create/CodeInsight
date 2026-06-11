#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
using  P=pair<ll,ll>;
int main(){
  ll N,K,ans=0;
  cin>>N>>K;
  for(ll i=0;i<N;i++){
    ll a;
    cin>>a;
    if(a>=K){ans++;}
  }
  cout<<ans<<endl;
}