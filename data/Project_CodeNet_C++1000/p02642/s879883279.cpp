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
  
  vector<ll> A(N);
  map<ll, ll> cnt;
  REP(i, N) { 
      cin >> A[i];
      cnt[A[i]]++;
  }
  sort(ALL(A));
  ll ans = 0;
  ll Amax = 1000000;
  vector<bool> dp(Amax+1, true);
  vector<bool> cnts(Amax+1, false);
  REP(i, N) {
    if (cnts[A[i]]) continue;
    cnts[A[i]] = true;
    for(ll j = A[i]*2; j <= Amax; j+=A[i]) {
      dp[j] = false;
    }
  }
  REP(i, N) {
    if (cnt[A[i]] == 1 && dp[A[i]]) ans++;
  }
  PRINT(ans);
  return 0;
} 
