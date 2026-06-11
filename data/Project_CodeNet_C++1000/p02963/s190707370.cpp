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
  long long S;
  cin >> S;
  long long X1, Y1, X2, Y2, X3, Y3;
  long long billion = pow(10, 9);
  X1 = 0;
  Y1 = 0;
  X2 = billion;
  Y2 = 1;
  X3 = billion - (S % billion);
  if (X3 >= billion)
    X3 = 0;
  Y3 = (S + X3) / billion;

  cout << X1 << " " << Y1 << " " << X2 << " " << Y2 << " " << X3 << " " << Y3 << endl;
  return 0;
}