// C++ 14
#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define loop(__x, __start, __end) for(int __x = __start; __x < __end; __x++)
void solve(); int main() { solve(); return 0; }

void solve() {
  ll n,k;
  cin >> n >> k;
  vector<int> A(n), F(n);
  loop(i,0,n) cin >> A[i];
  loop(i,0,n) cin >> F[i];
  sort(A.begin(), A.end());
  sort(F.rbegin(), F.rend());
  
  auto ok = [&](ll x, ll y) {
    ll total = 0;
    loop(i,0,n) {
      total += max(A[i]-x/F[i], 0LL);
    }
    return total <= y;
  };
  
  ll x,l=-1, r=1000000000000; // (10^6)^2+α
  while (l+1<r) {
    x = (l+r)/2;
    if (ok(x, k)) r=x;
    else l=x;
  }
  
  cout << r << endl;
}
