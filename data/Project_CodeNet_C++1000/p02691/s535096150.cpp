#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  map<int, int> MA;
  for (int i = 0; i < N; i++) {
    cin >> A.at(i);
    MA[i - A.at(i)]++;
    A.at(i) += i;
  }
  long ans = 0;
  for (auto a : A) ans += MA[a];
  cout << ans << "\n";
}