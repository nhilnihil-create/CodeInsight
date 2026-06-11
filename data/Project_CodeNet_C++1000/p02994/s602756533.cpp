#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  ll n, l;
  cin >> n>> l;
  ll a[n];
  ll m=10000;
  ll s=0;
  rep(i, n) {
    a[i]=l+i;
    s+=a[i];
  }
  
  rep(i, n) {
    m=min(m, max(a[i], -a[i]));
  }
  
  if(a[n-1]*a[0]<=0) cout<<s;
  else{
    if(a[0]>0) cout<<s-m;
    else cout<<s+m;
  }
}
