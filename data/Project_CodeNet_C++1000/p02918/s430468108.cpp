#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979;
const vector<int> dx = {1, 0};
const vector<int> dy = {0, 1};

int main() {
  int N, K;
  string S;
  cin >> N >> K >> S;
  int score = 0;
  for (int i=1; i<N; i++) {
    if (S[i-1]==S[i]) score++;
  }
  int res = min(score+2*K, N-1);
  cout << res << endl;
  return 0;
}