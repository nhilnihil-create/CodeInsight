#include <bits/stdc++.h>
using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> A(N);
  for (auto &i : A) cin >> i;
  
  long long int ans = 0;
  map<int, int> count;
  for (int i = 0; i < N; ++i) {
    ans += count[i-A[i]];
    count[i+A[i]]++;
  }
  cout << ans << endl;
}