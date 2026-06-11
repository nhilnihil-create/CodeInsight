//c++ -std=gnu++14 a.cpp
#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <iostream>
#include <istream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <vector>
#include <tuple>
#include <iomanip>
#include <climits>
#include <fstream>
#include <random>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
//typedef pair<ll, ll> P;
#define rep(i, n) for(int i = 0; i < (n); i++)
#define revrep(i, n) for(int i = (n)-1; i >= 0; i--)
#define pb push_back
#define f first
#define s second
#define chmin(x, y) x = min(x, y);
#define chmax(x, y) x = max(x, y);
#define len(x) ((int)(x).size())

//const ll INFL = LLONG_MAX;//10^18 = 2^60
const ll INFL = 1LL<<60;
//const int INF = INT_MAX;
const int INF = 1 << 30;//10^9
const ll MOD = 1000000007;
//const ll MOD = 998244353;
double EPS = 1e-10;

vector<ll> dy = {0, 1, 0, -1, 1, 1, -1, -1, 0};
vector<ll> dx = {1, 0, -1, 0, 1, -1, 1, -1, 0};

void pres(double A){printf("%.9lf\n", A);}
void BinarySay(ll x, ll y = 60){rep(i, y) cout << (x>>(y-1-i) & 1); cout << endl;}
ll cnt_bit(ll x){return __builtin_popcountll(x);}

ll pow_long(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2) res *= x;
    x *= x; k /= 2;
  }
  return res;
}

ll pow_mod(ll x, ll k){
  ll res = 1;
  while(k > 0){
    if(k % 2){
      res *= x; res %= MOD;
    }
    x *= x; x %= MOD;
    k /= 2;
  }
  return res;
}

ll inverse(ll x){return pow_mod(x, MOD - 2);};

ll gcd(ll a, ll b){
    if(b == 0) return a;
    return gcd(b, a % b);
}

ll lcm(ll x, ll y){
  ll res = x / gcd(x, y);
  res *= y;
  return res;
};


//コンビネーション
const int MAXcomb = 2000010;
ll fac[MAXcomb], finv[MAXcomb], inv[MAXcomb];
//facはn!,finvは1/n!
//invは逆元
void COMinit(){
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for(int i = 2; i < MAXcomb; i++){
        fac[i] = fac[i-1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD/i) % MOD;
        finv[i] = finv[i-1] * inv[i] % MOD;
    }
}
ll comb(int n, int k){
    if(n < k) return 0;
    if(n < 0 || k < 0) return 0;
    return fac[n] * finv[k] % MOD * finv[n-k] % MOD;
}


ll disit(ll s, ll base = 10){
  ll res = 0;
  while(s){
    res++;
    s /= base;
  }
  return res;
}



//エラトステネスの篩O(n);
ll prime[2000010];//i番目の素数
bool is_prime[2000011];
//n以下の素数の個数を全て返す関数
ll sieve(ll n){
    ll p = 0;
    for(ll i = 0; i <= n; i++) is_prime[i] = true;
    is_prime[0] = false;
    is_prime[1] = false;
    for(ll i = 2; i <= n; i++){
        if(is_prime[i]){
            prime[p++] = i;
            for(int j = 2 * i; j <= n; j += i) is_prime[j] = false;
        }
    }
    return p;
}

int N;
int A[1000010];
int B[1000010];

bool isPairwise(){
  bool res = true;
  rep(i, N){
    B[i] = A[i];
  }
  sieve(2000000);
  set<int> S;
  rep(i, 1010){
    if(i == 0){
      continue;
    }
    if(!is_prime[i]){
      continue;
    }
    rep(j, N){
      bool f = false;
      while(A[j] % i == 0){
        A[j] /= i;
        f = true;
      }
      if(f){
        if(S.count(i)){
          res = false;
          break;
        }
        S.insert(i);
      }
    }
  }

  set<int> S2;
  rep(i, N){
    if(A[i] == 1){
      continue;
    }
    if(S2.count(A[i])){
      res = false;
    }
    S2.insert(A[i]);
  }
  rep(i, N){
    A[i] = B[i];
  }
  return res;
}

bool isSetwise(){
  int GCD = A[0];
  rep(i, N){
    GCD = gcd(GCD, A[i]);
  }
  return GCD == 1;
}




void solve(){
  cin >> N;
  rep(i, N) cin >> A[i];
  if(isPairwise()){
    cout << "pairwise coprime" << endl;
  }else if(isSetwise()){
    cout << "setwise coprime" << endl;
  }else{
    cout << "not coprime" << endl;
  }
}

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  solve();
}
