#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
  int N;
  cin >> N;
  vector<int> P(N), Q(N), num(N);
  for (int i = 0; i < N; i++) {
    cin >> P[i];
    P[i]--;
  }
  for (int i = 0; i < N; i++) {
    cin >> Q[i];
    Q[i]--;
    
  }
  for (int i = 0; i < N; i++) num[i] = i;
  map<vector<int>, int> permutation;
  int cnt = 0;
  while (next_permutation(num.begin(), num.end())) {
    cnt++;
    permutation[num] = cnt;
  }
  cout << abs(permutation[P] - permutation[Q]) << endl;
}
