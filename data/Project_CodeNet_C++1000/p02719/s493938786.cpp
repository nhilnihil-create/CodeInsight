#include<bits/stdc++.h>
#define int long long
using namespace std;

signed main(){
  int n,k; cin>>n>>k;
  if(k==1){
    cout<<0<<endl;
    return 0;
  }
  if(n<=k-n){
    cout<<n<<endl;
    return 0;
  }
  n-=(n/k)*k;
  if(n<=k-n)
    cout<<n<<endl;
  else
    cout<<k-n<<endl;
}