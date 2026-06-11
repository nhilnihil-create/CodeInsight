#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> d(N);
  for (int i = 0; i < N; i++) {
  	cin >> d[i];
  }
  sort(d.begin(), d.end());
  int half = d.size() / 2;
  int before = d[half - 1];
  int after = d[half];
  int result = after - before;
  cout << result << endl;
}
