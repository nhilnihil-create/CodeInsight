#include <bits/stdc++.h>
using namespace std;

int main() {
  int N, M;
  cin >> N >> M;
  vector<int> price(N);
  for (int i = 0; i < N; i++) {
    cin >> price.at(i);
  }
  sort(price.begin(), price.end());
  int sum = 0;
  for (int i = 0; i < M; i++) {
    sum += price.at(i);
  }
  cout << sum << endl;
}