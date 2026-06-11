#include<bits/stdc++.h>
using namespace std;
int main() {
  int N; cin >> N;
  vector<int> v(N);
  for (int i = 0; i < N; i++) cin >> v[i];
  sort(v.begin(), v.end());
  int res = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      if (v[i] == v[j]) continue;
      for (int k = j + 1; k < N; k++) {
        if (v[j] == v[k]) continue;
        res += v[i] + v[j] > v[k];
      }
    }
  }
  cout << res << endl;
}
