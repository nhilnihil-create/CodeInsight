#include <bits/stdc++.h>
using namespace std;
using ll = long long;
typedef pair<int, int> P;
ll Mod = 1000000007;
int main() {
  int N,K;
  cin >> N >> K;
  string S;
  cin >> S;
  int ele = 1;
  for (int i = 1; i < N; i++) {
    if (S[i] != S[i - 1]) {
      ele++;
    }
  }
  cout << min(N - 1,N - ele + (2 * K)) << endl;
  return 0;
}