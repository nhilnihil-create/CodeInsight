#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#include <bitset>
#include <algorithm>
#include <complex>
#include <array>
#include <iomanip>
using namespace std;

#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define ALL(c) (c).begin(), (c).end()

typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<long double> VD;
typedef vector<VI> VVI;
typedef vector<VL> VVL;
typedef vector<VD> VVD;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

template<typename T> void chmin(T &a, T b) { if (a > b) a = b; }
template<typename T> void chmax(T &a, T b) { if (a < b) a = b; }

int in() { int x; scanf("%d", &x); return x; }
ll lin() { ll x; scanf("%lld", &x); return x; }
#define INF 1LL<<60

map< ll, ll > prime_factor(ll n) {
  map< ll, ll > ret;
  for(ll i = 2; i * i <= 4; i++) {
    while(n % i == 0) {
      ret[i]++;
      n /= i;
    }
  }
  if(n != 1) ret[n] = 1;
  return ret;
}

ll GCD(ll a, ll b) {
    if (b == 0) return a;
    else return GCD(b, a % b);
}

/* a と b の最小公倍数を求める */
ll LCM(ll a, ll b) {
    ll g = GCD(a, b);
    return a / g * b;
}

ll power(ll a, ll b)
{
     ll pow = 1;
     while ( b ) 
     {
            if ( b & 1 ) 
            {
              pow = pow * a;
              --b;
            }
            a = a*a;
            b = b/2;
     }
     return pow;
}

int main() {
    ll N, M;
    cin >> N >> M;
    vector<ll> a(N), b(N);
    vector< map<ll, ll> > factors(N);
    REP(i, N) {
        cin >> a[i];
        b[i] = a[i] / 2;
        factors[i] = prime_factor(b[i]);
    }

    ll n_2power_min = 1e9, n_2power_max = 0;
    REP(i, N) {
        n_2power_min = min(n_2power_min, factors[i][2]);
        n_2power_max = max(n_2power_max, factors[i][2]);
    }
    if(n_2power_min != n_2power_max) {
        cout << 0 << endl;
        return 0;
    }

    map<ll, ll> lcm_factors;
    ll lcm = 1;
    REP(i, N) {
        lcm = LCM(lcm, b[i]);
        if(lcm > M) {
            cout << 0 << endl;
            return 0;
        }
    }

    cout << (M / lcm - 1) / 2 + 1 << endl;
    return 0;
}
