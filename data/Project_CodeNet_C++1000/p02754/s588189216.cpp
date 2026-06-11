#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  int n,a,b; cin>>n>>a>>b;
  if(n%(a+b)==0){
    cout<<(n/(a+b))*a;
  }
  else if(n-n/(a+b)*(a+b)>a)
    cout<<n/(a+b)*a+a<<endl;
  else
    cout<<n/(a+b)*a+n-n/(a+b)*(a+b)<<endl;
}