#include<bits/stdc++.h>
using namespace std;
int n,q,i,j,s[10000],t,c;
main(){  
  for(cin>>n;i<n;cin>>s[i++]);
  for(cin>>q;j<q;++j)
    for(cin>>t,i=0;i<n;++i)
      if(t==s[i])c++,i=n;
  cout<<c<<endl;
}