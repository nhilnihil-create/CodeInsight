#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define ll long long
#define _GLIBCXX_DEBUG
const ll MOD = 1000000007;
const int MAX = 510000;

int main() {
  int N, ans = -1;
  cin >> N;
  vector<string> s(N);
  vector<int> t(N);
  for (int i=0; i<N; i++) cin >> s[i] >> t[i];
  string X;
  cin >> X;
  for (int i=0; i<N; i++) {
    if (s[i]==X) ans = accumulate(t.begin()+i+1, t.end(), 0);
  }
  cout << ans << endl;
}