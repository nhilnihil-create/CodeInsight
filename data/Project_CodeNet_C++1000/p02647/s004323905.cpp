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
  ll N, K;
  cin >> N >> K;
  
  vector<ll> A(N);
  REP(i, N) { 
      cin >> A[i];
  }

  REP(i, min(50LL, K)) {
    vector<ll> B(N);
    REP(j, N) {
      ll l = max(j - A[j], 0LL);
      ll r = min(j + A[j], N-1);
      B[l] ++;
      if (r+1 < N) B[r+1]--;
    }
    REP(j, N-1) {
      B[j+1] += B[j];
    }
    A = B;
  }
  PRINT(A);
  return 0;
} 
