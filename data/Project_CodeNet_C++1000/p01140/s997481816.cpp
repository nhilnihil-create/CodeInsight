#include<bits/stdc++.h>
#define N 1500
using namespace std;

  int cnth[1500001],cntw[1500001];

int main(){
  while(1){
    
    memset(cnth,0,sizeof(cnth)),memset(cntw,0,sizeof(cntw));
  int n,m;
  cin>>n>>m;
  if(n+m==0) break;
  int h[1500],w[1500];
  for(int i=0;i<n;i++)cin>>h[i];
  for(int i=0;i<m;i++)cin>>w[i];
  
  
  for(int i=0;i<n;i++){
    int ph=h[i];
    cnth[ph]++;
    for(int j=i+1;j<n;j++)ph+=h[j],cnth[ph]++;
  }
  
  for(int i=0;i<m;i++){
    int pw=w[i];
    cntw[pw]++;
    for(int j=i+1;j<m;j++)pw+=w[j],cntw[pw]++;
    }
  
  int ans=0;
  for(int i=1;i<=1500000;i++)if(cnth[i]>0 && cntw[i]>0)ans+=(cnth[i]*cntw[i]);
  
  cout<<ans<<endl;
  }
  return 0;
}