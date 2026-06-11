#include <bits/stdc++.h>

#define loop(s, e, i) for (int i = s; i < e; ++i)
#define print(s) cout << s << endl;
using namespace std;
using ll = long long;
using lld = long long;

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
  ll N, K;
  cin >> N >> K;
  vector<double> A(N);

  loop(0, N, i) {
    double tmp;
    cin >> tmp;
    double sum = tmp * (1+tmp) / 2;
    A[i] = sum / tmp ;
  }

  vector<double> C(N+1);
  C[0] = 0;
  loop(0, N, i) {
    C[i+1] = A[i] + C[i];
  }

  double mx = 0;
  loop(0, N-K+1, i) {
    double score = C[i+K] - C[i];
    mx = max(mx, score);
  }
  cout << fixed << setprecision(9) << mx << endl;
}