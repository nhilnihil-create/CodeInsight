#include <bits/stdc++.h>
using namespace std;
 
using ll = long long;
constexpr ll mod = 1e9 + 7;
#define endl '\n'
 
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
 
  vector<ll> A(5);
  for (auto& _a : A) cin >> _a;
  ll t1 = A[0]*60 + A[1];
  ll t2 = A[2]*60 + A[3];
  if (t2 < t1) t2 += 24*60;
  t2 -= t1;
  t2 -= A.back();
  t2 = max(t2, 0LL);
  cout << t2 << endl;
                 
  

}
