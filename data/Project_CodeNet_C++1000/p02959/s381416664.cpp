#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(void){
  int n;
  cin>>n;
  vector<int> a(n+1);
  for(int i=0;i<n+1;i++){
    cin>>a[i];
  }
  vector<int> b(n);
  for(int i=0;i<n;i++){
    cin>>b[i];
  }
  ll ans=0;
  for(int i=0;i<n+1;i++){
    int n0=min(a[i],b[i]);
    ans+=n0;
    b[i]-=n0;
    int n1=min(a[i+1],b[i]);
    ans+=n1;
    a[i+1]-=n1;
  }
  cout<<ans<<endl;
  return 0;
}