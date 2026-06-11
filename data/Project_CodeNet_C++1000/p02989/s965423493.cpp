#include <bits/stdc++.h>
using namespace std;

int main() {
  int N; cin >> N;
  vector<int> d(N); for (int i =0; i<N; i++) cin >> d.at(i);
  sort(d.begin(),d.end());
  int ans = d.at(N/2) - d.at(N/2 - 1);
  if (ans <= 0) {
    cout << 0 << endl;
  } else {
    cout << ans << endl;
  }
}