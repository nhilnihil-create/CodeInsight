#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;

int main(){
  int n;cin>>n;
  map<int, ll> count;
  for(int i=0;i<n;i++){
    int num;cin>>num;
    if(i==0 && num!=0){cout<<0<<endl;return 0;}
    count[num]++;
  }
  if(count[0]!=1LL){cout<<0<<endl;return 0;}
  int pre=-1;
  for(auto& e: count){
    if(pre+1!=e.first){cout<<0<<endl;return 0;}
    pre=e.first;
  }
  ll ans=1LL;
  for(int i=1;i<count.size();i++){
    ll t=count[i-1];
    if(t==1LL)continue;
  	for(int j=0;j<int(count[i]);j++){
      ans=(ans*t)%998244353;
    }
  }
  cout<<ans<<endl;
  return 0;
}