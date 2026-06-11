#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
  ll N, A, B;
  cin >> N >> A >> B;
  if(A == 0 && B == 0) {
    cout << 0 << endl;
  }
  else {
    ll Q = N % (A+B);
    if(Q > A) {
      cout << (N / (A+B) + 1) * A << endl;
    }
    else {
      cout << (N / (A + B)) * A + Q << endl;
    }
  }
}
