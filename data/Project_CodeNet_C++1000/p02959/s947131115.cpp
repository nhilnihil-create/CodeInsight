#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int n,b,c;
  cin>>n;
  vector<int> a(n+1);
  long long ans=0;
  rep(i,n+1) cin>>a[i];
  rep(i,n){
    cin>>b;
    c=a[i+1]+a[i];
    ans+=min(c,b);
    a[i+1]=clamp(c-b,0,a[i+1]);
  }
  cout<<ans<<endl;
}