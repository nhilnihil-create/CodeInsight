#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<int> a(n+1),b(n);
  rep(i,n+1) cin >> a[i];
  rep(i,n) cin >> b[i];
  ll ans = 0;
  rep(i,n){
    ans += min(a[i]+a[i+1],b[i]);
    a[i+1] = clamp(a[i]+a[i+1]-b[i],0,a[i+1]);
  }
  cout << ans << endl;
}