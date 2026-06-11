#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N;
  cin >> N;
  int a[N+1];
  a[0] = -1;
  int boal[N+1];
  vector<int> ans; 
  for (int i = 1; i < N+1; i++) {
    cin >> a[i];
    boal[i] = -1;
  }
  for (int i = N; i >= 1; i--) {
    int cnt = 0;
    for (int j = i * 2; j <= N; j+=i) {
      if (boal[j] == 1) {
        cnt++;
      }
    }
    if (cnt % 2 == a[i]) {
      boal[i] = 0;
    } else {
      boal[i] = 1;
      ans.push_back(i);
    }
  }
  cout << ans.size() << endl;
  for (int i = 0; i < ans.size(); i++) {
    cout << ans[i] << endl;
  }
  return 0;
}