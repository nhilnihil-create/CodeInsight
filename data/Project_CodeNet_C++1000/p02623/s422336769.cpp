#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  int n,m,k;
  cin >> n >> m >> k;
  vector<int> a(n);
  vector<int> b(m);
  rep(i,n) cin >> a[i];
  rep(i,m) cin >> b[i];
  vector<ll> sa(n+1);
  vector<ll> sb(m+1);
  rep1(i,n) sa[i] = sa[i-1]+a[i-1];
  rep1(i,m) sb[i] = sb[i-1]+b[i-1];
  int ans = 0;
  rep(i,n+1){
    if(sa[i] > k) break;
    int ok = 0;
    int ng = m+1;
    while(abs(ok-ng)>1){
      int mid = (ok+ng)/2;
      if(sa[i]+sb[mid] > k) ng = mid;
      else ok = mid;
    }
    ans = max(ans,i+ok);
  }
  cout << ans << endl;
}
