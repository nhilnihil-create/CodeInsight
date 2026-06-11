#include <bits/stdc++.h>
#define FOR(i, a, b) for (ll i = a; i <= (ll)(b); i++)
#define LOOP while (true)
using namespace std;
typedef long long ll;

int main()
{
  ll K;
  cin >> K;

  if (K <= 10)
  {
    cout << K << endl;
    return 0;
  }

  vector<string> xs = {"1", "2", "3", "4", "5", "6", "7", "8", "9"};
  ll cnt = 9;
  LOOP
  {
    vector<string> ys;

    for (string x : xs)
    {
      ll h = x[x.length() - 1] - '0';
      FOR(i, h - 1, h + 1)
      {
        if (i < 0 || 9 < i)
          continue;

        string y = x + to_string(i);
        ys.push_back(y);
        cnt++;
        if (cnt == K)
        {
          cout << y << endl;
          return 0;
        }
      }
    }

    xs = ys;
  }

  return 0;
}