#include <bits/stdc++.h>

#define all(a) (a).begin(),(a).end()
#define rall(a) (a).rbegin(),(a).rend()
#define rep(i,n) for(ll i=0,i##_len=(n);i<i##_len;i++)
#define brep(i,a,b) for(ll i=(a),i##_len=(b);i<=i##_len;i++)
#define rrep(i,n) ll i=(n);ll now=-1;while(i--&&(now++||1))
#define xrep(i,n) for(ll i=1,i##_len=(n);i<=i##_len;i++)
#define Yes(n) cout<<((n)?YES:NO)<<'\n'
#define rYes(n) cout<<((n)?YES:NO)<<'\n';return
#define co(n) cout<<(n)<<'\n'
#define rco(n) cout<<(n)<<'\n';return
#define Sort(v) sort(all(v))
#define rSort(v) sort(all(v)); reverse(all(v))
#define Unique(v) (v).erase(unique(all(v)),(v).end())
#define eb emplace_back

using namespace std;
using ll = long long;
using vll = vector<ll>;
using vbl = vector<bool>;
using vint = vector<int>;
using vvll = vector<vll>;
using vstr = vector<string>;

const ll INF = 1e18;

// --- functions which take 1 argument ---
static inline void ignore_ret(int x){x++;}
template<class T> inline int sgn(T x){return (x>0)-(x<0);}
template<class T> inline ll factorial(T n){if(n==0)return 1;ll r=1;for(T i=2;i<=n;i++)r*=i;return r;}
template<class T> inline map<T,T> factorize(T n){map<T,T>r;for(T i=2;i*i<=n;i++){while(n%i==0){r[i]++;n/=i;}}if(n!=1)r[n]=1;return r;}
template<class T> inline vector<T> divisor(T n){vector<T>r;for(T i=1;i*i<=n;i++){if(!(n%i)){r.eb(i);if(i*i!=n)r.eb(n/i);}}Sort(r);return r;}

// --- functions which take 2 arguments ---
template<class T> inline bool chmax(T&a,const T&b){if(a<b){a=b;return 1;}return 0;}
template<class T> inline bool chmin(T&a,const T&b){if(a>b){a=b;return 1;}return 0;}
template<class T> inline T nPr(T n,T k){if(n<k||n<0||k<0)return 0;T r=1;for(T i=n-k+1;i<=n;i++)r*=i;return r;}
template<class T> inline T nCr(T n,T k){if(n<k||n<0||k<0)return 0;T r=1;k=min(k,n-k);for(T i=n-k+1;i<=n;i++)r*=i;return r/factorial(k);}

// --- functions which take vector(s) as argument(s) ---
template<class T> inline void print(T v){cout<<"[ ";for(auto x:v)cout<<x<<' ';cout<<"]\n";}
template<class T> inline void print_d(T v){for(auto x:v)cout<<x;cout<<'\n';}
template<class T> inline void print_all(T v){for(auto x:v)cout<<x<<'\n';}
template<class T> inline T min(vector<T>v){return *min_element(all(v));}
template<class T> inline T max(vector<T>v){return *max_element(all(v));}
template<class T> inline ll sum(T v){return reduce(all(v),0LL);}
template<class T> inline T gcd(vector<T>v){return reduce(v.begin()+1,v.end(),v[0],gcd<T,T>);}
template<class T> inline T lcm(vector<T>v){return reduce(all(v),(T)1,lcm<T,T>);}
template<class T> inline double abs(T v){return sqrt(reduce(all(v),0.0,[](int s,int v){return s+=v*v;}));}
template<class T> inline T vector_add(T u,T v){ll s=u.size();if(s>v.size())return {};T r;rep(i,s)r.eb(u[i]+v[i]);return r;}
template<class T> inline T vector_subtract(T u,T v){ll s=u.size();if(s>v.size())return {};T r;rep(i,s)r.eb(u[i]-v[i]);return r;}
template<class T> inline T dot_product(vector<T>u,vector<T>v){if(u.size()<v.size())return 0;T r=0;for(T i=0;i<u.size();i++)r+=u[i]*v[i];return r;}
template<class T> inline T cross_product(T u,T v){T r(3);r[0]=u[1]*v[2]-u[2]*v[1];r[1]=u[2]*v[0]-u[0]*v[2];r[2]=u[0]*v[1]-u[1]*v[0];return r;}

// --- functions which take set(s) as argument(s) ---
template<class T> inline T min(set<T>v){return *min_element(all(v));}
template<class T> inline T max(set<T>v){return *max_element(all(v));}
template<class T> inline T gcd(set<T>v){T r=0;for(T x:v)r=(r==0)?x:gcd(r,x);return r;}
template<class T> inline T lcm(set<T>v){T r=0;for(T x:v)r=(r==0)?x:lcm(r,x);return r;}

// --- Template ends here ---

ll to_change(string S) {
  ll cnt = 1, to_return = 0;
  brep(i, 1, (ll)S.size() - 1) {
    if (S[i] != S[i-1]) {
      to_return += cnt/2;
      cnt = 1;
    } else {
      cnt++;
    }
  }
  return to_return + cnt/2;
}

void solve(string S, ll K) {
  string Sp = S;
  Sort(Sp); Unique(Sp);
  if (Sp.size() == 1) { rco((S.size() * K) / 2); }
  ll ans_1 = to_change(S), ans_2 = to_change(S + S);
  rco((ans_2 - ans_1) * (K-1) + ans_1);
}

int main() {
  string S;
  cin >> S;
  ll K;
  ignore_ret(scanf("%lld",&K));
  solve(S, K);
  return 0;
}
