#include<bits/stdc++.h>
using namespace std;
int f(int n,int d){
  return n/d;
}
int main(){
  int l,r,d;
  cin>>l>>r>>d;
  int ans=f(r,d)-f(l-1,d);
  cout<<ans<<endl;
  return 0;
}