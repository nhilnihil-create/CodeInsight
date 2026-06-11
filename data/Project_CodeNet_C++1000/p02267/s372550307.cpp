#include<bits/stdc++.h>
using namespace std;
int n,q,i,j,s[10000],t,c;
main(){  
  cin>>n;
  for(;i<n;cin>>s[i++]);
  cin>>q;
  for(;j<q;++j){
    cin>>t;
    for(i=0;i<n;++i)(t-s[i])||(c++,i=n);
  }
  cout<<c<<endl;
}