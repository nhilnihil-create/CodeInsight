#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;

int main() {
  int K, A, B;
  cin >> K >> A >> B;

  // B以下の最大のKの倍数がA以上である
  if (A <= (B / K) * K)
    cout << "OK" << endl;
  else
    cout << "NG" << endl;

  return 0;
}