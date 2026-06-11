#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
typedef long long ll;
using namespace std;
int main()
{
  long long N;
  cin >> N;
  string res = "";
  while (N)
  {
    N--;
    res += (char)('a' + (N % 26));
    N /= 26;
  }
  reverse(res.begin(), res.end());
  cout << res << endl;
}