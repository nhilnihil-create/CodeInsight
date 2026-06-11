#include <bits/stdc++.h>
#include <unordered_map>

using namespace std;
typedef long long int ll;
typedef long double ld;
#define REP(i, n) for(ll i = 0LL; i < (ll)(n); i++)
#define REPR(i, n) for (ll i = (ll)(n) - 1; i >= 0; i--)
#define FOR(i, n, m) for(ll i = (ll)n; i < (ll)(m); i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007
#define INF (1LL << 62)

#define PI (acos(-1))
#define PRINT(x) std::cout << x << endl
 
ll gcd(ll a, ll b) { return b ? gcd(b,a%b) : a;}
ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }
ll countDigit(ll n) { return floor(log10(n) + 1); } 
typedef pair <ll,ll> P;
static const ll dx[8] = {0,1,0,-1, 1, -1, 1, -1}, dy[8] = {1,0,-1,0,1,1,-1,-1};

template <typename T> 
ostream& operator<<(ostream& os, const vector<T>& v) 
{ 
    for (int i = 0; i < (int)v.size(); ++i) os << v[i] << " ";  
    return os; 
}

template <typename T1, typename T2> 
ostream& operator<<(ostream& os, const map<T1, T2>& m) 
{ 
    for (auto p : m) os << "<" << p.first << ", " << p.second << "> "; 
    return os; 
}

int main()
{ 
  ll N;
  cin >> N;
  
  vector<ll> A(N+1);
  ll sum = 0;
  REP(i, N+1) { 
      cin >> A[i];
      sum += A[i];
  }
  ll notleaf = 1 - A[0];
  if (notleaf < 0) {
    PRINT(-1);
    return 0;
  }
  sum -= A[0];
  if (notleaf > sum) {
    PRINT(-1);
    return 0;
  }

  ll ans = 1;
  FOR(i, 1, N+1) {
    ll tmp = 2*notleaf - A[i];
    if (tmp < 0) {
      PRINT(-1);
      return 0;
    }
    sum -= A[i];
    if (tmp > sum) {
      tmp = sum;
    }
    notleaf = tmp;
    ans += A[i] + notleaf;
  }
  PRINT(ans);
  return 0;
} 
