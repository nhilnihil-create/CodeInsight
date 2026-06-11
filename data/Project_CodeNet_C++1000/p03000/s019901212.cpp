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
  int N, X;
  cin >> N >> X;
  vector<int> vec(N+1, 0);
  REP(i, N) {
    int x;
    cin >> x;
    vec[i+1] = vec[i] + x;
  }
  REP(i, N+1) {
    if (vec[i+1] > X) {
      cout << i+1 << endl;
      return 0;
    }
  }
  cout << N+1 << endl;
  
  
  return 0;
}