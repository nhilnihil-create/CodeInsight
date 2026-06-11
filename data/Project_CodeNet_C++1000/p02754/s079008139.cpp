#include <bits/stdc++.h>
using namespace std;
int main() {
  long long N,A,B,ans=0; cin >> N >> A >> B;
  ans = N/(A+B) * A;
  long long left = N % (A+B);
  ans += min(left,A);
  cout << ans << endl;
}