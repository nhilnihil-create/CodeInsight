#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;

int main() {
  string S;
  cin >> S;
  int N = S.size();
  vector<int> M;
  int cnt = 0;
  for (int i = 1; i < N; i++) {
    if (S[i-1] == S[i]) {
      cnt++;
    } else {
      cnt++;
      M.push_back(cnt);
      cnt = 0;
    }
  }
  M.push_back(cnt+1);
  for (int i = 0; i < M.size(); i+=2) {
    int r = M[i];
    int l = M[i+1];
    int rnum = ((r+1)/2) + (l/2);
    int lnum = r + l - rnum;
    for (int j = 0; j < r - 1; j++) {
      cout << 0 << " ";
    }
    cout << rnum << " " << lnum << " ";
    for (int j = 0; j < l - 1; j++) {
      cout << 0 << " ";
    }
  }
  cout << endl;
  return 0;
}
