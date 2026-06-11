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


int main() {
  int N;
  cin >> N;
  vector<int> E(N);
  loop(0, N, i) {
    cin >> E[i];
  }

  sort(E.begin(), E.end());
  int ans = 0;
  for (int i=N-1; i>=0; i--) {
    for (int j=i-1; j>=0; j--) {
      auto iter = lower_bound(E.begin(), E.end(), E[i]+E[j]);
      ll ng = distance(iter, E.end());
      ans += (N - 1- i) - ng;
    }
  }
  print(ans);
}