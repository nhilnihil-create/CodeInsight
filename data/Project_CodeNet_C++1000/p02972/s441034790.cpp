#include<bits/stdc++.h>
using namespace std;
signed main(){
  int n,m=0;
  int a[500000],b[500000]={};
  cin>>n;
  for(int i=0;i<n;i++) cin>>a[i];
  for(int i=n-1;i>=0;i--){
    int q=i+1,sum=0,j=1;
    //cout<<i<<" ";
    while(true){
      if(q>n) break;
      //cout<<q<<" ";
      q=(i+1)*j;
      sum+=b[q-1];
      j++;
    }
    //cout<<sum<<"\n";
    if(sum%2!=a[i]) b[i]=1,m++;
  }
  cout<<m<<"\n";
  for(int i=0;i<n;i++){
    if(b[i]==1){
      cout<<i+1;
      if(i!=n-1) cout<<" ";
    }
  }
  cout<<"\n";
}
