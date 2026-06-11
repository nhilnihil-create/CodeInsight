#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)
#define rep1(i, n) for(int i = 1; i < n+1; i++)
#define all(A) A.begin(),A.end()
typedef long long ll;

int main(){
  int n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  sort(all(a));
  reverse(all(a));
  ll ans = 0;
  rep(i,n-1){
    ans += a[(i+1)/2];
  }
  cout << ans << endl;
}