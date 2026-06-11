#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main() {
  int N;  cin >> N;
  vector<int> a(N);

  for (int i = 0; i < N; ++i) cin >> a[i];

  sort(a.begin(), a.end());

  cout << ((a[a.size() / 2]) - (a[a.size() / 2 - 1])) << endl;

  return 0;
}