#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> A(N);
  int sum = 0;
  rep(i, N) {
    cin >> A.at(i);
    sum += A.at(i);
  }
  sort(A.begin(), A.end());
  if (A.at(N - M) * 4 * M < sum) {
    cout << "No" << endl;
  } else {
    cout << "Yes" << endl;
  }
}
