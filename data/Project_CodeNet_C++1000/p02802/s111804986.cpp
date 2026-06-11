#include <bits/stdc++.h>
using namespace std;
 
int main () {
  int N, M;
  cin >> N >> M;
  vector<int> ok(N);
  int ans1 = 0;
  vector<int> memo(N);
  int ans2 = 0;
  for (int i = 0; i < M; i++) {
    int a;
    string b;
    cin >> a >> b;
    if (ok.at(a - 1) == 0 && b == "WA") {
      memo.at(a - 1)++;
    }
    else if (ok.at(a - 1) == 0 && b == "AC") {
      ans1++;
      ans2 += memo.at(a - 1);
      ok.at(a - 1) = 1;
    }
  }
  cout << ans1 << " " << ans2 << endl;
}
     
