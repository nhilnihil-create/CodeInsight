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
  long long ans = 1;
  vector<long long> A(N);
  for (int i = 0; i < N; i++) {
    cin >> A[i];
    if (A[i] == 0) {
      cout << 0 << endl;
      return 0;
    }
  }
  for (int i = 0; i < N; i++) {
    if(ans >= LLONG_MAX / A[i] || ans * A[i] >= 1000000000000000001){
      ans = -1;
      break;
    } else {
      ans *= A[i];
    }
  }
  cout << ans << endl;
}
