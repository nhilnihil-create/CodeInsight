#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
int main(){
  int n,b;
  cin>>n;
  vector<int> a(n+1);
  long long ans=0;
  rep(i,n+1) cin>>a[i];
  rep(i,n){
    cin>>b;
    ans+=min(a[i],b);
    b=max(0,b-a[i]);
    ans+=min(a[i+1],b);
    a[i+1]=max(0,a[i+1]-b);
  }
  cout<<ans<<endl;
}