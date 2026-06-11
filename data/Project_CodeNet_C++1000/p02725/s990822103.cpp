#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll = long long;
int main(){
  int k,n,ans;
  cin>>k>>n;
  int a[n];
  rep(i,n) cin>>a[i];
  ans = a[1] - a[0];
  rep(i,n-1) ans = max(ans,a[i+1]-a[i]);
  ans = max(ans,k+a[0]-a[n-1]);
  cout<<k-ans<<endl;
}