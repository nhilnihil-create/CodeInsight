#include<bits/stdc++.h>
using namespace std;
using ll=long long;

int main(){
  int i,j,cnt=0;
  int n;
  cin>>n;
  ll x[n],y[n];
  for(i=0;i<n;i++)cin>>x[i]>>y[i];
  if(n==1){
    cout<<1;
    return 0;
  }
  ll X[n*n],Y[n*n];
  for(i=0;i<n;i++){
    for(j=0;j<n;j++){
      if(i!=j){
        X[cnt]=x[j]-x[i];
        Y[cnt++]=y[j]-y[i];
      }
    }
  }
  int m=cnt;cnt=0;
  vector<pair<ll,ll>> v;
  for(i=0;i<m;i++){
    v.push_back(pair<ll,ll>(X[i],Y[i]));
  }
  sort(v.begin(),v.end());
  int c[m];
  for(i=0;i<m;i++)c[i]=1;
  for(i=1;i<m;i++){
    if(v[i]==v[i-1])c[cnt]++;
    else cnt++;
  }
  m=cnt+1;cnt=0;
  for(i=0;i<m;i++){
    cnt=max(cnt,c[i]);
  }
  cout<<n-cnt;
}