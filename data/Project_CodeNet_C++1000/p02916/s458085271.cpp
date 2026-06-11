#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
  int n,s=0; cin>>n;
  int a[n],b[n],c[n];
  rep(i,n) cin>>a[i],a[i]--;
  rep(i,n) cin>>b[i];
  rep(i,n-1) cin>>c[i];
  rep(i,n){
    s+=b[i];
    if(a[i]&&a[i]-1==a[i-1]) s+=c[a[i-1]];
  }
  cout<<s;
}