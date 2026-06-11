#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  ll N, A, B;
  cin >> N >> A >> B;
  if (A % 2 == 0 && B % 2 == 0)
  {
    cout << (B - A) / 2 << endl;
    return 0;
  }
  else if (A % 2 != 0 && B % 2 != 0)
  {
    cout << (B - A) / 2 << endl;
    return 0;
  }
  cout << min(A - 1LL, N - B) + 1 + (B - A - 1LL) / 2 << endl;
  return 0;
}