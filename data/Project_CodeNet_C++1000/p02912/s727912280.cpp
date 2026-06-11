#include <iostream>
#include <queue>
using namespace std;

#define REP(i, n) for (int i = 0; i < n; i++)
#define ALL(v) v.begin(), v.end()

int main()
{
  int a, N, M;
  priority_queue<int> A;
  long long res = 0;
  cin >> N >> M;
  REP(i, N)
  {
    cin >> a;
    A.push(a);
  }
  REP(i, M)
  {
    a = A.top();
    A.pop();
    A.push(a / 2);
  }

  REP(i, N)
  {
    res += A.top();
    A.pop();
  }
  cout << res << endl;
  return 0;
}
