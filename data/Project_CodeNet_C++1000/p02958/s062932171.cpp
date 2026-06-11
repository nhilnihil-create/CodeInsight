#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
typedef long long ll;
int main() {
  ll n; cin>>n;
  ll a[n];
  rep(i, n) cin >> a[i];
  ll cnt=0;
  rep(i, n) {
    if(a[i]!=i+1) cnt++;
  }
  if(cnt<=2) cout << "YES";
  else cout << "NO";
}