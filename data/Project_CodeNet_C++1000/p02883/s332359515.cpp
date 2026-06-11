#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;

int main(){
  int n; cin >> n;
  ll k; cin >> k;
  vector<int> a(n), f(n);
  rep(i, n) cin >> a[i];
  rep(i, n) cin >> f[i];

  sort(a.begin(), a.end());
  sort(f.rbegin(), f.rend());

  ll left = 0, right = 1000000000005, mid;

  while(left < right){
    mid = (left + right) / 2;
    ll sum = 0;
    rep(i, n){
      sum += max(a[i] - mid / f[i], 0LL);
    }
    if(sum <= k){
      right = mid;
    }
    else{
      left = mid + 1;
    }
  }
  cout << left << endl;


  return 0;
}
