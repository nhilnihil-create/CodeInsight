// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)

int main() {
  ll n; cin >> n;
  vector<ll> A(n+1), B(n);
  loop(i,0,n+1) cin >> A[i];
  loop(i,0,n) cin >> B[i];
  ll cnt = 0;
  loop(i,0,n) {
    ll &b = B[i];
    ll &a = A[i];
    ll d = min(b, a);
    a -= d;
    b -= d;
    
    ll &a2 = A[i+1];
    ll d2 = min(b, a2);
    a2 -= d2;
    b -= d2;
    cnt += d + d2;
  }
  cout << cnt << endl;
  return 0;
}
