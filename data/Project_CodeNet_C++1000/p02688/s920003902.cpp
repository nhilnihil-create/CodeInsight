#include <bits/stdc++.h>
using namespace std;

int main(){
  int i,n,k,j,x,y,kotae;
  cin>>n>>k;
  int a[n];
  for(i=0;i<n;i++){
    a[i]=0;
  }
  for(i=0;i<k;i++){
    cin>>x;
    for(j=0;j<x;j++){
      cin>>y;
      a[y-1]++;
    }
  }
  for(i=0;i<n;i++){
    if(a[i]==0){
      kotae++;
    }
  }
  cout<<kotae;
}
    