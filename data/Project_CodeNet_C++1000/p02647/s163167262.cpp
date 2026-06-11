#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

int main()
{
  int N, K;
  cin >> N >> K;
  vector<int> A(N + 1);
  rep(i, N)
  {
    cin >> A[i];
  }

  rep(i, min(K, 100))
  {
    vector<int> temp(N + 1);
    rep(j, N)
    {
      int left = max(0, j - A[j]);
      int right = min(N - 1, j + A[j]);
      temp[left]++;
      temp[right + 1]--;
    }

    rep(j, N)
    {
      temp[j + 1] += temp[j];
    }
    A = temp;
  }

  rep(i, N)
  {
    cout << A[i] << " ";
  }
  cout << endl;
  return 0;
}