#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  ll n; cin>>n;
  ll a[100];
  rep(i, n) cin>>a[i];
  
  ll s=0;
  rep(i, n) {
    ll b; cin>>b;
    s+=b;
  }
  
  ll c[100];
  rep(i, n-1) cin>>c[i];
  
  rep(i, n-1) {
    if(a[i]+1==a[i+1]) s+=c[a[i]-1];
  }
  
  cout << s;
}