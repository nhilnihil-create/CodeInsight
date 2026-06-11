#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
// 素因数分解
vector<pair<long long, long long>> prime_factorize(long long N)
{
  vector<pair<long long, long long>> res;
  for (long long a = 2; a * a <= N; ++a)
  {
    if (N % a != 0)
      continue;
    long long ex = 0; // 指数

    // 割れる限り割り続ける
    while (N % a == 0)
    {
      ++ex;
      N /= a;
    }

    // その結果を push
    res.push_back({a, ex});
  }

  // 最後に残った数について
  if (N != 1)
    res.push_back({N, 1});
  return res;
}

int main()
{
  cout << fixed << setprecision(10);
  ll A,B;
  cin >> A >> B;
  ll N = gcd(A,B);
  vector<pair<long long, long long>> vec = prime_factorize(N);
  cout << vec.size() + 1 << endl;
  return 0;
}
