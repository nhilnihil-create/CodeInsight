#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int K, A, B;
  cin >> K >> A >> B;
  int tmp = B - B % K;
  if (tmp >= A && tmp <= B) {
    cout << "OK" << endl;
  } else {
    cout << "NG" << endl;
  }
}
