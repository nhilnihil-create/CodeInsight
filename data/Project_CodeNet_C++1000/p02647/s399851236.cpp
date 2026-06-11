#include<bits/stdc++.h>
using namespace std;


int main(){
  cin.tie(0);
  ios_base::sync_with_stdio(false);
  int  n,k;
  cin>>n>>k;
  int a[200005];
  int b[200005];
  for(int i=0;i<n;i++){
    cin>>a[i];
    b[i]=0;
  }
  b[n]=0;
  int d=min(50,k);
 
  for(int j=0;j<d;j++){
  for(int i=0;i<n;i++){
    int l=max(0,i-a[i]);
    int r=min(n,i+a[i]+1);
    b[l]++;
    b[r]--;
  }
    for(int i=1;i<n;i++){
     b[i]+=b[i-1];
      
    }
    for(int i=0;i<n;i++){
    a[i]=b[i];
      b[i]=0;
    }
   
  }
 
  
  for(int i=0;i<n;i++){
  cout<<a[i]<<" ";
  }
  






}