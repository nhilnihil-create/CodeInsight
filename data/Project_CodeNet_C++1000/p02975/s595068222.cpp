#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
#define irep(i, n) for (int i = (n); i >= 0; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;
const int INF = 1 << 30;
 
int main() {
  ll n;
  cin >> n;
  vector<ll> a(n);
  rep(i,n) cin >> a[i];
  ll num = 0;
  rep(i,n) num = num ^ a[i];
  bool can = true;
  if (num == 0) {
    sort(a.begin(), a.end());
    if (n % 3 == 0) {
      rep(i,n) {
        if (i < n/3) {
          if (a[i] != a[0]) can = false;
        } 
        else if (i < 2*n / 3) {
          if (a[i] != a[n/3]) can = false;
        } 
        else {if (a[i] != a[2*n/3]) can = false;}
      }
      if (((a[0]^a[n/3])^a[2*n/3]) != 0) can = false;
      
    } else {
      rep(i,n) if (a[i] != 0) can = false;
    }
  } 
  else can = false;
  
  if (can) cout << "Yes" << endl;
  else cout << "No" << endl;
}