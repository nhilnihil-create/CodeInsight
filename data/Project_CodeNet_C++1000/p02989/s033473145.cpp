#include <bits/stdc++.h>
#define REP(i, n) for(int i = 0; i < n; i++)
#define REPR(i, n) for(int i = n; i >= 0; i--)
#define FOR(i, m, n) for(int i = m; i < n; i++)
#define INF 2e9
#define ALL(v) v.begin(), v.end()
using namespace std;
typedef long long ll;
int main()
{
  int N;
  cin >> N;
  vector<int> vec(pow(10, 5)+1, 0);
  REP(i, N) {
    int x;
    cin >> x;
    vec[x]++;
  }
  vector<int> seq(pow(10, 5)+1, 0);
  for(int i = 1; i <= seq.size(); i++) {
    seq[i] = seq[i-1] + vec[i];
  }
  int ans = 0;
  REP(i, seq.size()) {
    if (seq[i] == N / 2) {
      ans++;
    }
  }
  cout << ans << endl;
  return 0;
}