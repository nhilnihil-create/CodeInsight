#include<bits/stdc++.h>
using namespace std;
int main(){
  int n;
  cin>>n;
  vector<int> a(n,0);
    int x[20][20]={},y[20][20]={};
  for(int i=0;i<20;i++) for(int j=0;j<20;j++) x[i][j]=0,y[i][j]=0;
  for(int i=0;i<n;i++){
     cin>>a[i];
     for(int j=0;j<a[i];j++){
         cin>>x[i][j]>>y[i][j];
         x[i][j]=x[i][j]-1;
     }
  }
  int ans=0;
  for(int bit=0;bit<(1<<n);bit++){
   int flag=0;
    for(int l=0;l<n;l++){
      if(!(bit&(1<<l))) continue;
      
        for(int j=0;j<a[l];j++){
         if(y[l][j]==1&&!(bit&(1<<x[l][j]))) flag=1;
         if(y[l][j]==0&&(bit&(1<<x[l][j]))) flag=1;
      
      }
    }
    if(!flag){
      int count=0;
      for(int i=0;i<n;i++){
        if(bit&(1<<i)) ++count;
      }
      ans=max(ans,count);
    }
  }
  cout<<ans<<endl;
  return 0;
}