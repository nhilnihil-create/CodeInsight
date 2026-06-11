#include <bits/stdc++.h>
#define rep(i,n) for (int i=0;i<n;i++)
using namespace std;
using ll = long long;

int main() {
  int n,m,k;
  cin >> n >> m >> k ;
  vector<int>a(n),b(m);
  rep(i,n) cin >> a.at(i);
  rep(i,m) cin >> b.at(i);
  int ans =0;
  ll sumb=0;
  rep(i,m) sumb+=b.at(i);
  ll t=sumb;
  int j=m;
  rep(i,n+1) {
    while (t>k && j>0) {
      j--;
      t-=b.at(j);
    }
    if (t>k) break;
    ans=max(ans,i+j);
    if(i==n) break;
    t+=a[i];
  }
  cout << ans << endl;
}

