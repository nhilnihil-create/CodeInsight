

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

vector<pair<ll, ll>> prime_factorize(ll N) {
  vector<pair<ll, ll>> results;
  for (ll i=2; i*i<N; i++) {
    if (N%i != 0) continue;
    ll ex = 0;
    while(N%i == 0) {
      ex++;
      N /= i;
    }
    results.push_back(make_pair(i, ex));
  }
  if ( N!= 1) results.push_back({N, 1});
  return results;
}

int main() {
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll A, B;
    cin >> A >> B;
    ll x = gcd(A, B);

    auto results = prime_factorize(x);

    print(results.size() + 1);
}