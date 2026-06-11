#include <bits/stdc++.h>

#include <fstream>
using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  cout << setprecision(20) << fixed;
  /*
  ifstream in("input.txt");
  cin.rdbuf(in.rdbuf());
  //*/
  int N;
  cin >> N;
  vector<int> L(N);
  for (int i = 0; i < N; i++) cin >> L[i];
  int ans = 0;
  sort(L.begin(), L.end());
  for (int i = 0; i < N - 2; i++) {
    for (int j = i + 1; j < N - 1; j++) {
      for (int t = j + 1; t < N; t++) {
        if (L[i] != L[j] && L[j] != L[t] && L[i] != L[t]) {
          if (L[i] + L[j] > L[t]) {
            ans++;
          }
        }
      }
    }
  }
  cout << ans << endl;
}