

#include <bits/stdc++.h>

#define loop(s, e, i) for (int i = s; i < e; ++i)
#define print(s) cout << s << endl;
using namespace std;
using ll = long long;

/*
浮動小数点の入力
cout << fixed << setprecision(9) << endl;
*/

ll gcd(ll a, ll b)
{
  if (a < b)
  {
    return gcd(b, a);
  }
  while (b != 0)
  {
    ll tmp = b;
    b = a % b;
    a = tmp;
  }
  return a;
}

struct Data
{
  int r, l, k;
};

int main()
{
  ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  int N;
  cin >> N;

  map<string, ll> M;

  loop(0, N, i)
  {
    string S;
    cin >> S;
    sort(S.begin(), S.end());
    if (M.find(S) != M.end())
    {
      M[S] = M[S] + 1;
    }
    else
    {
      M[S] = 1;
    }
  }
  ll sum = 0;
  for (auto &x : M)
  {
    if (x.second == 1) {
      continue;
    }
    sum += x.second*(x.second-1) / 2;
  }
  print(sum);
}