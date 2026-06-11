#include <bits/stdc++.h>
#define ALL(a) (a).begin(), (a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define pb push_back
#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define rep(i, n) FOR(i, 0, n)
#define ll long long
using namespace std;

const ll P = 1000000007;
int gcd(int a, int b) { return b != 0 ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
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
  ll N;
  cin >> N;
  vector<pair<ll,ll>> vec;
  vec = prime_factorize(N);
  ll n = vec.size();
  ll ans = 0;
  rep(i,n)
  {
    if(vec[i].second<3)
    {
      ans ++;
    }
    else if(vec[i].second<6)
    {
      ans += 2;
    }
    else if(vec[i].second<10)
    {
      ans += 3;
    }
    else if(vec[i].second<15)
    {
      ans += 4;
    }
    else if(vec[i].second<21)
    {
      ans += 5;
    }
    else if(vec[i].second<28)
    {
      ans += 6;
    }
    else if(vec[i].second<36)
    {
      ans += 7;
    }
    else if(vec[i].second<45)
    {
      ans += 8;
    }
  }
  cout << ans << endl;
  return 0;
}
