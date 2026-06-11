#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int MOD=998244353;

int main(){
  int i,j,cnt=0;
  int n;
  cin>>n;
  int d[n];
  for(i=0;i<n;i++)cin>>d[i];
  if(n==1){
    cout<<1<<endl;
    return 0;
  }
  if(d[0]!=0){
    cout<<0<<endl;
    return 0;
  }
  sort(d,d+n);
  if(d[1]==0){
    cout<<0<<endl;
    return 0;
  }
  for(i=1;i<n;i++){
    if(!(d[i]==d[i-1] || d[i]==d[i-1]+1)){
      cout<<0<<endl;
      return 0;
    }
  }
  ll c[n];
  for(i=0;i<n;i++)c[i]=1;
  for(i=1;i<n;i++){
    if(d[i]==d[i-1])c[cnt]++;
    else cnt++;
  }
  n=cnt+1;
  ll prod=1;
  for(i=2;i<n;i++){
    for(j=0;j<c[i];j++){
      prod=(prod*c[i-1])%MOD;
    }
  }
  cout<<prod<<endl;
}