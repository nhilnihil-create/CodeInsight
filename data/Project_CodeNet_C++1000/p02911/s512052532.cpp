// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  ll n, k, q; cin >> n >> k >> q;
  vector<ll> A(q), B(n);
  loop(i,0,q) cin >> A[i];
  loop(i,0,q) A[i]--;
  loop(i,0,n) B[i] = k-q;
  loop(i,0,q) B[A[i]] += 1;
  loop(i,0,n) {
    if (B[i]<=0) cout << "No" << endl;
    else cout << "Yes" << endl;
  }
  return 0;
}
