#include <bits/stdc++.h>
#define int long long
using namespace std;

signed main() {
  int n,k,keta,x; cin>>n>>k;
  keta=1; x=k-1;
  while(x<n){
    x+=(x+1)*(k-1);
    keta++;
  }
  cout<<keta<<endl;
}