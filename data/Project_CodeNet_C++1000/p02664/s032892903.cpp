#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define FOR(i, s, e) for (int i = (int)(s); i <= (int)(e); i++)
#define printYesNo(is_ok) puts(is_ok ? "Yes" : "No");
#define SORT(v) sort(v.begin(), v.end());
#define RSORT(v) sort(v.rbegin(), v.rend());
#define REVERSE(v) reverse(v.begin(), v.end());

template <typename T>
void printlnVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << endl;
  }
}

template <typename T>
void printVector(T v)
{
  rep(i, v.size())
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  string S;
  cin >> S;
  int N = S.size();
  rep(i, N - 1)
  {
    if (S[i + 1] == '?' && S[i] == 'P')
      S[i + 1] = 'D';
  }

  rep(i, N)
  {
    if (S[i] == '?')
      S[i] = 'D';
  }
  cout << S << endl;
  return 0;
}