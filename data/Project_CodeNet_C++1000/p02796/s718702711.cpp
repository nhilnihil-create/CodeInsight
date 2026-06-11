#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const ll Mod = 998244353;
const int MAX = 510000;
const double PI = 3.14159265358979323846;

int main() {
  int N;
  cin >> N;
  vector<int> X(N), L(N);
  for (int i=0; i<N; i++) cin >> X[i] >> L[i];
  vector<pair<int, int>> V(N);
  for (int i=0; i<N; i++) {
    V[i].first = X[i]+L[i];
    V[i].second = X[i]-L[i];
  }
  sort(V.begin(), V.end());
  // cur:現在選んでいる区間のうち、最も右にあるやつの右端
  int res = 0, cur = -INT_MAX;
  for (int i=0; i<N; i++) {
    if (cur>V[i].second) continue; // 被るやつは飛ばす
    res++;
    cur = V[i].first;
  }
  cout << res << endl;
  return 0;
}