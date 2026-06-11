#include <bits/stdc++.h>
using namespace std;

int main() {
  long long N, sum = 0;
  cin >> N;

  vector<long long> vec(N);
  for (int i = 0; i < N; i++) {
    cin >> vec[i];
    sum += vec[i];
  }

  long long lef = 0;
  int cut = 0;
  while (lef < sum / 2) {
    lef += vec[cut];
    cut++;
  }

  long long lef2 = lef - vec[cut - 1];

  long long ri = 0;
  for (int i = cut; i < N; i++) {
    ri += vec[i];
  }

  long long ri2 = ri + vec[cut - 1];

  cout << min(abs(lef - ri), abs(lef2 - ri2)) << endl;
}
