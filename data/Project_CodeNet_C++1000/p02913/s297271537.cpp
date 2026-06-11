#include <bits/stdc++.h>
//typedef
//-------------------------#include <bits/stdc++.h>
 
const double pi = 3.141592653589793238462643383279;
 
 
using namespace std;
 
template<typename T=int>inline T readT() {
  char c = getchar_unlocked(); bool neg = (c=='-');
  T res = neg?0:c-'0';
  while(isdigit(c=getchar_unlocked())) res = res*10 + c-'0';
  return neg?-res:res;
}
template<typename T=int>inline void writeT(T x, char c='\n'){
  int d[20],i=0; if(x<0)putchar_unlocked('-'),x*=-1;
  do{d[i++]=x%10;}while(x/=10); while(i--)putchar_unlocked('0'+d[i]);
  putchar_unlocked(c);
}
 
//typedef
//------------------------------------------
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef pair<int, int> PII;
typedef pair<long long, long long> PLL;
typedef pair<int, PII> TIII;
typedef long long LL;
typedef unsigned long long ULL;
typedef vector<LL> VLL;
typedef vector<VLL> VVLL;
 
 
//container util
 
//------------------------------------------
#define ALL(a)  (a).begin(),(a).end()
#define RALL(a) (a).rbegin(), (a).rend()
#define PB push_back
#define MP make_pair
#define SZ(a) int((a).size())
#define SQ(a) ((a)*(a))
#define EACH(i,c) for(typeof((c).begin()) i=(c).begin(); i!=(c).end(); ++i)
#define EXIST(s,e) ((s).find(e)!=(s).end())
#define SORT(c) sort((c).begin(),(c).end())
 
 
//repetition
//------------------------------------------
#define FOR(i,s,n) for(int i=s;i<(int)n;++i)
#define REP(i,n) FOR(i,0,n)
#define MOD 1000000007
 
 
#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define trav(a, x) for(auto& a : x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
 
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
const double EPS = 1E-8;
 
#define chmin(x,y) x=min(x,y)
#define chmax(x,y) x=max(x,y)
 
class UnionFind {
public:
    vector <int> par; 
    vector <int> siz; 

    UnionFind(int sz_): par(sz_), siz(sz_, 1) {
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
    void init(int sz_) {
        par.resize(sz_);
        siz.assign(sz_, 1LL);
        for (ll i = 0; i < sz_; ++i) par[i] = i;
    }
 
    int root(int x) { 
        while (par[x] != x) {
            x = par[x] = par[par[x]];
        }
        return x;
    }
 
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y) return false;
        if (siz[x] < siz[y]) swap(x, y);
        siz[x] += siz[y];
        par[y] = x;
        return true;
    }
 
    bool issame(int x, int y) { 
        return root(x) == root(y);
    }
 
    int size(int x) { 
        return siz[root(x)];
    }
};
 
 
ll modPow(ll x, ll n, ll mod = MOD){
    ll res = 1;
    while(n){
        if(n&1) res = (res * x)%mod;
 
        res %= mod;
        x = x * x %mod;
        n >>= 1;
    }
    return res;
}
 
#define SIEVE_SIZE 5000000+10
bool sieve[SIEVE_SIZE];
void makeSieve(){
    for(int i=0; i<SIEVE_SIZE; ++i) sieve[i] = true;
    sieve[0] = sieve[1] = false;
    for(int i=2; i*i<SIEVE_SIZE; ++i) if(sieve[i]) for(int j=2; i*j<SIEVE_SIZE; ++j) sieve[i*j] = false;
}
 
bool isprime(ll n){
    if(n == 0 || n == 1) return false;
    for(ll i=2; i*i<=n; ++i) if(n%i==0) return false;
    return true;
}
 
const int MAX = 2000010;
long long fac[MAX], finv[MAX], inv[MAX];
 
// テーブルを作る前処理
void COMinit() {
    fac[0] = fac[1] = 1;
    finv[0] = finv[1] = 1;
    inv[1] = 1;
    for (int i = 2; i < MAX; i++){
        fac[i] = fac[i - 1] * i % MOD;
        inv[i] = MOD - inv[MOD%i] * (MOD / i) % MOD;
        finv[i] = finv[i - 1] * inv[i] % MOD;
    }
}
 
// 二項係数計算
long long COM(int n, int k){
    if (n < k) return 0;
    if (n < 0 || k < 0) return 0;
    return fac[n] * (finv[k] * finv[n - k] % MOD) % MOD;
}
 
long long extGCD(long long a, long long b, long long &x, long long &y) {
    if (b == 0) {
        x = 1;
        y = 0;
        return a;
    }
    long long d = extGCD(b, a%b, y, x);
    y -= a/b * x;
    return d;
}
// 負の数にも対応した mod (a = -11 とかでも OK) 
inline long long mod(long long a, long long m) {
    return (a % m + m) % m;
}
 
// 逆元計算 (ここでは a と m が互いに素であることが必要)
long long modinv(long long a, long long m) {
    long long x, y;
    extGCD(a, m, x, y);
    return mod(x, m); // 気持ち的には x % m だが、x が負かもしれないので
}
ll GCD(ll a, ll b){
    
    if(b == 0) return a;
    return GCD(b, a%b);
}

typedef vector<ll> vec;
typedef vector<vec> mat;

mat mul(mat &A, mat &B) {
    mat C(A.size(), vec((int)B[0].size()));
    for(int i=0; i<A.size(); ++i){
        for(int k=0; k<B.size(); ++k){
            for(int j=0; j<B[0].size(); ++j){
                C[i][j] = (C[i][j] + A[i][k] * B[k][j] %MOD) % MOD;
            }
        }
    }
    return C;
}
mat matPow(mat A, ll n) {
    mat B(A.size(), vec((int)A.size()));
 
    for(int i=0; i<A.size(); ++i){
        B[i][i] = 1;
    }
 
    while(n > 0) {
        if(n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

map<ll,ll> prime_factor(ll n) {
  map<ll,ll> res;
  for(ll i=2; i*i <= n; i++) {
      while(n%i == 0) {
          res[i]++;
          n /= i;
      }
  }

  if(n != 1) res[n] = 1;
  return res;
}
using ld= long double;
template<typename T = int> struct BIT{
  vector<T> node;

  int N;
  BIT(int n){
    N = n;
    node.resize(N+1);
  }

  void add(int i, T x){
    i++;
    while(i <= N){
      node[i] += x;
      i += (i & -i);
    }
  }

  T sum(int i){
    T res = 0;
    while(i > 0){
      res += node[i];
      i -= (i & -i);
    }
    return res;
  }

  

};


struct RollingHash{

    using ull = unsigned long long;
    const ull mod = (1UL << 61) - 1;
    const ull MASK30 = (1UL << 30) - 1;
    const ull MASK31 = (1UL << 31) - 1;

    const ull MASK61 = mod;

    ull base;
    int n;
    vector<ull> hash, pow;

    RollingHash(string s)
    {
        random_device rnd;
        mt19937_64 mt(rnd());
        base = calc_mod(mt()) % 100000 + 1000;
        
        n = (int)s.size();
        hash.assign(n+1, 0);
        pow.assign(n+1, 1);
        
        for(int i=0; i<n; i++){
            hash[i+1] = calc_mod(mul(hash[i], base) + s[i]);
            pow[i+1] = calc_mod(mul(pow[i], base));
        }
    }

    ull calc_mod(ull x){
        ull xu = x >> 61;
        ull xd = x & MASK61;
        ull res = xu + xd;
        if(res >= mod) res -= mod;
        return res;
    }

    ull mul(ull a, ull b){
        ull au = a >> 31;
        ull ad = a & MASK31;
        ull bu = b >> 31;
        ull bd = b & MASK31;
        ull mid = ad * bu + au * bd;
        ull midu = mid >> 30;
        ull midd = mid & MASK30;
        return calc_mod(au * bu * 2 + midu + (midd << 31) + ad * bd);
    }

    //[l,r)のハッシュ値
    inline ull get(int l, int r){
        ull res = calc_mod(hash[r] + mod*4-mul(hash[l], pow[r-l]));
        return res;
    }

    //string tのハッシュ値
    inline ull get(string t){
        ull res = 0;
        for(int i=0; i<t.size(); i++){
            res = calc_mod(mul(res, base)+t[i]);
        }
        return res;
    }

    //string s中のtの数をcount
    inline int count(string t) {
        if(t.size() > n) return 0;
        auto hs = get(t);
        int res = 0;
        for(int i=0; i<n-t.size()+1; i++){
            if(get(i, i+t.size()) == hs) res++; 
        }
        return res;
    }

    // LCPを求める S[a:] T[b:]
    inline int LCP(int a, int b){
        int len = min((int)hash.size()-a, (int)hash.size()-b);
        
        int lb = -1, ub = len+1;
        while(ub-lb>1){
            int mid = (lb+ub)/2;

            if(get(a, a+mid) == get(b, b+mid)) lb = mid;
            else ub = mid;
        }
        return lb;
    }
};
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(5);
    
    int N;
    string s;
    cin >> N >> s;

    RollingHash rh(s);

    auto check = [&](int d) -> bool {

        map<unsigned long long , unsigned long long> prev;
        for(int i=0; i+d <= N; i++){
            auto aba = rh.get(i, i+d);
            if(prev.count(aba)){
                if(i - prev[aba] >= d) return true;
            }else
                prev[aba] = i;
        }
        return false;
    };
    int lb = 0, ub = N/2+1;
    while(ub-lb>1){
        int mid = (lb+ub) >> 1;
        if(check(mid)) lb = mid;
        else ub = mid;
    }
    
    cout << lb << endl;
    return 0;
}
