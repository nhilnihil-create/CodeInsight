#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void calculate(vector<int>& a, vector<int>& b, vector<int>& c, vector<int>& d,
	       vector<int>& A, int N, int M, int Q, int index, int prev,
	       int& ans)
{
  if (index > N)
    return;
  int sum = 0;
  for (int i = 0; i < Q; i++){
    if (A[b[i] - 1] - A[a[i] - 1] == c[i])
      sum += d[i];
    ans = max(ans, sum);
  }
  for (int i = prev; i <= M; i++){
    A[index] = i;
    calculate(a, b, c, d, A, N, M, Q, index + 1, i, ans);
  }
}

int main(void)
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int N, M, Q, ans = 0;
  cin >> N >> M >> Q;
  vector<int> a(Q), b(Q), c(Q), d(Q), A(N, 0);
  for (int i = 0; i < Q; i++)
    cin >> a[i] >> b[i] >> c[i] >> d[i];
  calculate(a, b, c, d, A, N, M, Q, 0, 1, ans);
  cout << ans << '\n';
  return 0;
}
