#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int N;
  cin >> N;
  vector<int> S((1 << N));
  for (int i = 0; i < (1 << N); i++) cin >> S[i];
  sort(S.begin(), S.end(), greater<int>());
  multiset<int> M;
  vector<int> X = {S[0]};
  for (int i = 1; i < (1 << N); i++) M.insert(S[i]);

  for (int i = 0; i < N; i++) {
    int c = X.size();
    for (int j = 0; j < c; j++) {
      auto iter = M.lower_bound(X[j]);
      if (iter != M.begin()) {
        X.push_back(*prev(iter));
        M.erase(prev(iter));
      } else {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  return 0;
}