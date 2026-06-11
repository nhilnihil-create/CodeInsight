#include<bits/stdc++.h>
using namespace std;
int main(){
  int p,q,r;
  cin>>p>>q>>r;
  int ans=0;
  ans=max(max(p,q),r);
  int count=p+q+r-ans;
  cout<<count<<endl;
}