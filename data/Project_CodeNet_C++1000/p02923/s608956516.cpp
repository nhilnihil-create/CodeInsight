// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  ll n; cin >> n;
  vector<ll> A(n);
  loop(i,0,n) cin >> A[i];
  int cur = 0, max_ = 0;
  loop(i,1,n) {
    if (A[i]<=A[i-1]) {
      cur++;
      max_ = max(max_, cur);
    } else {
      cur = 0;
    }
  }
  cout << max_ << endl;
  return 0;
}
