#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
typedef long long ll;
int main() {
  int n,ans=0;
  cin>>n;
  vector<int> a(n);
  rep(i,n) cin>>a[i];
  rep(i,n-1){
    for(int j=i+1;j<n;j++){
      ans+=a[i]*a[j];
    }
  }
  cout<<ans;
}