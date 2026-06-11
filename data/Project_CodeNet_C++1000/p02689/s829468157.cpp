#include <bits/stdc++.h>
using namespace std;

int main(){
  int i,n,m,x,y,kotae=0;
  cin>>n>>m;
  int h[n],w[n],c[n];
  for(i=0;i<n;i++){
    cin>>h[i];
    w[i]=0;
    c[i]=0;
  }
  for(i=0;i<m;i++){
    cin>>x>>y;
    x--;
    y--;
    if(h[x]>h[y]){
      w[x]++;
    }else if(h[x]<h[y]){
      w[y]++;
    }
    c[x]++;
    c[y]++;
  }
  for(i=0;i<n;i++){
    if(c[i]==w[i]){
      kotae++;
    }
  }
  cout<<kotae;
}
    