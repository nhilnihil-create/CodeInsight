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
  int N, A, B, C, D;
  string S;
  cin >> N >> A >> B >> C >> D >> S;
  bool AisOK = true, BisOk = true, croosisOK = true;
  for (int i = A - 1; i < C - 1; i++)
  {
    if (S[i] == '#' && S[i + 1] == '#')
      AisOK = false;
  }

  for (int i = B - 1; i < D - 1; i++)
  {
    if (S[i] == '#' && S[i + 1] == '#')
      BisOk = false;
  }

  if (D < C)
  {
    croosisOK = false;

    for (int i = B - 1; i <= D - 1; i++)
    {
      if (S[i - 1] == '.' && S[i] == '.' && S[i + 1] == '.')
        croosisOK = true;
    }
  }
  if (AisOK && BisOk && croosisOK)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}