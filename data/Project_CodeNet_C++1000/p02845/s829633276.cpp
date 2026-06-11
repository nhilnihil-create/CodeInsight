#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
using ll=long long;
ll mod=1e9+7;

int main() {
  int n;
  cin>>n;
  int a[n];
  rep(i,n) cin>>a[i];
  int b=0,c=0,d=0;
  ll ans=1;
  rep(i,n){
    int cnt=0;
    if(b==a[i]) cnt++;
    if(c==a[i]) cnt++;
    if(d==a[i]) cnt++;
    ans*=cnt;
    ans%=mod;
    if(b==a[i]) b++;
    else if(c==a[i]) c++;
    else d++;
  }
  cout<<ans<<endl;
}