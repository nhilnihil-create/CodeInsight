#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main() {
  int n,s=0,p=99; cin>>n;
  int a[n],b[n],c[n];
  rep(i,n) cin>>a[i],a[i]--;
  rep(i,n) cin>>b[i];
  rep(i,n-1) cin>>c[i];
  for(int t:a){
    s+=b[t];
    if(p==t-1) s+=c[p];
    p=t;
  }
  cout<<s;
}