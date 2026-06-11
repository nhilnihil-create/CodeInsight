#include <iostream>
using namespace std;

#define REP(n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

int main()
{
  int N, K, Q;
  cin >> N >> K >> Q;
  int A[Q];
  int res[N];
  REP(N) res[i] = 0;
  REP (Q)
  {
    int a;
    cin >> a;
    res[a - 1]++;
  }
  REP (N) cout << (Q - res[i] < K ? "Yes" : "No") << endl;
}
