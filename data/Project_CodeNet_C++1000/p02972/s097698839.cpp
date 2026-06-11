#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (ll)(n); ++i)
#define rep2(i, s, n) for (ll i = s; i < (ll)(n); i++)
#define repr(i, n) for (ll i = n; i >= 0; i--)
#define pb push_back
#define COUT(x) cout << (x) << endl
#define COUTF(x) cout << setprecision(15) << (x) << endl
#define ENDL cout << endl
#define DF(x) x.erase(x.begin())  // 先頭文字削除
#define ALL(x) x.begin(), x.end()
#define SORT(x) sort(ALL(x))
#define REVERSE(x) reverse(ALL(x))
#ifdef _DEBUG
#define debug(x) cout << "[debug] " << #x << ": " << x << endl
#else
#define debug(x)
#endif
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<ll, ll>;
constexpr ll INF = 0x3f3f3f3f3f3f3f3f;
constexpr double PI = 3.141592653589793238462643383279;
ll getDigit(ll x) {
  return x == 0 ? 1 : log10(x) + 1;
}

ll gcd(ll x, ll y) {
  return y ? gcd(y, x % y) : x;
}

ll lcm(ll a, ll b) {
  return a / gcd(a, b) * b;
}

vector<P> factorize(ll n) {
  vector<P> result;
  for (ll i = 2; i * i <= n; ++i) {
    if (n % i == 0) {
      result.pb({i, 0});
      while (n % i == 0) {
        n /= i;
        result.back().second++;
      }
    }
  }
  if (n != 1) {
    result.pb({n, 1});
  }
  return result;
}

signed main() {
  ll N;
  cin >> N;

  vector<ll> A;
  A.pb(0);
  rep(i, N) {
    ll a;
    cin >> a;
    A.pb(a);
  }

  vector<ll> ans(N + 1);
  repr(i, N) {
    ll sum = 0;
    // debug(i);
    if (i == 0) {
      continue;
    }
    rep(j, N / i) {
      // debug(j);
      ll index = j + 1;
      if (j == 0) {
        sum += A[i];
      } else {
        sum += ans[i * index];
      }
    }
    // debug(sum);

    ans[i] = sum % 2;
  }

  ll count = 0;
  vector<ll> outputs;
  rep(i, N + 1) {
    if (i == 0) {
      continue;
    }
    if (ans[i] == 1) {
      count++;
      outputs.pb(i);
    }
  }

  COUT(count);
  rep(i, outputs.size()) {
    if (i == 0) {
      cout << outputs[i];
    } else {
      cout << " " << outputs[i];
    }
  }
  if (count != 0) {
    ENDL;
  }
  return 0;
}