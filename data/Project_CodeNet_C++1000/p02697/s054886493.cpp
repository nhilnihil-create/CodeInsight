#include <bits/stdc++.h>
using namespace std;
#define ll long long
const int MOD=1e9+7;
const long double Pi=acos(-1);
using  P=pair<ll,ll>;
int main(){
  ll N,M;
  cin>>N>>M;
  for(ll i=0;i<M;i++){
    if(N%2==1){cout<<i+1<<" "<<N-i<<endl;}
  }
  if(N%2==0){
    for(ll i=0;i<(M/2+M%2);++i){
      cout<<i+1<<" "<<N/2-i<<endl;
    }
    for(ll i=0;i<M/2;i++){
      cout<<N/2+i+1<<" "<<N-i-1<<endl;
    }
  }
}