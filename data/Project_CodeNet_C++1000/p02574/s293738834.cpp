#include<bits/stdc++.h>
using namespace std;
int main(void){
  int m=0,n,l=0; cin>>n;
  unordered_map<int,int> mp;
  for(int i=0; i<n; ++i){
    int a; cin>>a;
    ++mp[a]; m=max(m,a);
  }
  vector<bool> b(m+1,true);
  for(int i=2; i<=m; ++i){
    int s=0;
    if(b[i]==true) for(int j=1; i*j<=m; ++j) {b[i*j]=false; s+=mp[i*j];}
    if(s==n){ cout<<"not coprime"; return 0;}
    else l=max(l,s);
  }
  if(l<2){ cout<<"pairwise coprime"; return 0;}
  else cout<<"setwise coprime";
  return 0;
}
