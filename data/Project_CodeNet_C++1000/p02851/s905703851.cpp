#include <bits/stdc++.h>
using namespace std;
#define rep(i,m,n) for(int i=m;i<n;i++)
typedef pair<int,int> P;
typedef long long ll;

int main() {
  int n;
  ll k;
  cin>>n>>k;
  ll a[n];
  rep(i,0,n) cin>>a[i];
  ll s[n+1];
  s[0]=0;
  rep(i,0,n) s[i+1]=s[i]+a[i];
  ll t[n];
  rep(i,0,n+1) s[i]=(s[i]-i)%k;
  map<ll,ll> b;
  ll ans=0;
  rep(i,0,n+1){
    ans+=b[s[i]];
    b[s[i]]++;
    if(i+1-k>=0) b[s[i+1-k]]--;
  }
  cout<<ans<<endl;
}
