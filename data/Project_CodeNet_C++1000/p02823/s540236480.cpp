#include <iostream>

using namespace std;
using ll = long long;

int main() {
  ll N, A, B, ans;
  cin >> N >> A >> B;
  ans = abs(A-B)/2;
  if ((A-B)%2) {
    ans += min(min(A,B), min(N-A,N-B)+1);
  }
  cout << ans << endl;
}
