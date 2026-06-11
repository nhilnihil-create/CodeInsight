#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
int main() {
  ll A,B,N;
  cin >> A >> B >> N;
  ll p = min(B-1,N);
  ll ans = A*p/B;
  cout << ans << endl;
}