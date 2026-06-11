#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;

int main() {
  int n;
  cin >>n;
  ll total = 0;
  vector<ll> a(n);
  rep(i,n) {
    cin>>a[i];
    total += a[i];
  }
  ll minx = total, sum = 0;
  rep(i,n){
    sum += a[i];
    minx = min(minx, abs(sum-(total-sum)));
  }
  cout << minx << endl;
  return 0;
}
