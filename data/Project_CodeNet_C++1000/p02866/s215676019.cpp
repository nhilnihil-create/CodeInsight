#include <bits/stdc++.h>
using namespace std;
using ll=long long;
const ll MOD=998244353;

int main(){
  int n; cin>>n;
  int a; cin>>a;
  if(a!=0){
    cout<<0<<endl;
    return 0;
  }
  vector<ll> num(n+1,0);
  ll maxnum=0;
  for(int i=0;i<n-1;i++){
    int x; cin>>x;
    num[x]++;
    maxnum=max(maxnum,ll(x));
  }
  if(num[0]>0){
    cout<<0<<endl;
    return 0;
  }
  
  for(int i=1;i<=maxnum;i++){
    if(num[i]==0){
      cout<<0<<endl;
      return 0;
    }
  }
  ll ans=1;
  for(int i=1;i<maxnum;i++){
    for(int j=0;j<num[i+1];j++){
      ans*=num[i];
      ans%=MOD;
    }
  }
  cout<<ans<<endl;
} 