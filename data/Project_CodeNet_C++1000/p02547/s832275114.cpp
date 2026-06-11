#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
int MOD = 1000000007;

int main() {
  int N; cin >> N;
  vector<vector<int>> D(N, vector<int>(2));
  for (int i = 0; i < N; i++) cin >> D[i][0] >> D[i][1];
  
  bool ans = false;
  int cnt = 0;
  for (int i = 0; i < N; i++) {
    if (D[i][0] == D[i][1]) cnt++;
    else cnt = 0;
    
    if (cnt == 3) ans = true;
  }
  
  if (ans) cout << "Yes" << endl;
  else cout << "No" << endl;
}    