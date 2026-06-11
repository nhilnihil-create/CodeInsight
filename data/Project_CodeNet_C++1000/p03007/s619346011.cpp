#include <bits/stdc++.h>
using namespace std;

int main()
{
  int64_t N, n = 0, s = 0;
  cin >> N;
  vector<int64_t> A(N);
  for (int i = 0; i < N; i++)
  {
    cin >> A[i];
    if (A[i] < 0)
      n++;
    s += abs(A[i]);
  }
  sort(A.begin(), A.end());
  if (N == 2)
  {
    cout << A[1] - A[0] << endl;
    cout << A[0] << ' ' << A[1] << endl;
    return 0;
  }
  if (n == 0)
  {
    cout << s - 2 * A[0] << endl;
    cout << A[0] << ' ' << A[1] << endl;
    int64_t f = A[0] - A[1]; // minus
    for (int i = 2; i < N - 1; i++)
    {
      cout << f << ' ' << A[i] << endl;
      f -= A[i];
    }
    cout << A[N - 1] << ' ' << f << endl;
  }
  else if (n == N)
  {
    cout << s + 2 * A[N - 1] << endl;
    cout << A[N - 2] << ' ' << A[N - 1] << endl;
    int64_t l = A[N - 1] - A[N - 2];
    for (int i = 1; i < N - 2; i++)
    {
      cout << l << ' ' << A[i] << endl;
      l -= A[i];
    }
    cout << l << ' ' << A[0] << endl;
  }
  else
  {
    cout << s << endl;
    int64_t f = A.at(0), l = A.at(N - 1);
    for (int i = 1; i < N - 1; i++)
    {
      if (A.at(i) < 0)
      {
        cout << l << ' ' << A.at(i) << endl;
        l -= A.at(i);
      }
      else
      {
        cout << f << ' ' << A.at(i) << endl;
        f -= A.at(i);
      }
    }
    cout << l << ' ' << f << endl;
  }
}
