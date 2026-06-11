#include <bits/stdc++.h>
using namespace std;
template<class T> ostream& operator<<(ostream &os, vector<T> V) { os << "[ "; 
  for(auto v:V)os << v << " "; return os << "]";
}
template<class T> ostream& operator<<(ostream &os, set<T> S){ os << "{ "; 
  for(auto s:S) os<<s<<" ";  return os<<"}"; 
}
template<class L, class R> ostream& operator<<(ostream &os, pair<L,R> P) {
  return os<<"("<<P.first<<","<< P.second << ")";
}
template<class L, class R> ostream& operator<<(ostream &os, map<L,R> M) {
  os<<"{ ";for(auto m:M)os<<"("<<m.first<<":"<<m.second<<")";
  return os<<"}";
}
#define cerr cout
#define TRACE
#ifdef TRACE
#define trace(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}
#else
#define trace(...) 1
#endif
// #include <ext/pb_ds/assoc_container.hpp> 
// #include <ext/pb_ds/tree_policy.hpp> 
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// find_by_order(k)  returns iterator to kth element starting from 0;
// order_of_key(k) returns count of elements strictly smaller than k;
//For multiset use less_equal operator but it does support erase operations for multiset
#define ll long long
#define ld long double
#define vll vector<ll>
#define pll pair<ll,ll>
#define vpll vector<pll>
#define I insert 
#define pb push_back
#define F first
#define S second
#define endl "\n"
#define all(v) (v).begin(),(v).end()
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpii;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mp make_pair


const int mod = 1e9+7;

inline int add(int a,int b){a+=b;if(a>=mod)a-=mod; return a;} 
inline int sub(int a,int b){a-=b;if(a<0) a += mod; return a;}
inline int mul(int a, int b){ return a*1ll*b%mod;}
inline int power(int x, ll y){
  int res = 1;
  while(y){
    if(y&1) res = mul(res , x);
    x = mul(x,x);
    y >>= 1;
  }
  return res;
}
const int N = 5e3 + 100;
const ll INF = 1e18;

vector<vll> v;
int P[N];
ll C[N];

bool vis[N];


ll k;
ll solve(vll &vec){
  //cout << vec <<endl;
  ll tot = 0;
  ll n = vec.size();
  for(auto it : vec) tot += it;
  ll ans = tot*(k/n);
  ll p = k%n;
  vll q = vec;
  for(auto it : vec) q.push_back(it);
  if(p == 0) return ans;
  //cout << q << endl;
  ll curr = 0;
  ll mx = -INF;
  //cout << p << ' ' << n << endl;
  for(int i = 0;i < p-1; ++i){
    curr += q[i]; 
  }
  for(int i = p-1;i < 2*n; ++i){
    curr += q[i];
    mx = max(mx , curr);
    curr -= q[i-(p-1)];
  }
  //cout << tot+mx << endl;
  return ans+mx;
}

int main(){
  fio; cout<<fixed<<setprecision(25);	
  int n; cin >> n;
  cin >> k;
  for(int i =1 ;i <= n ; ++i) cin >> P[i];
  for(int i =1;i <= n ; ++i) cin >> C[i];

  for(int i = 1;i <= n ; ++i){
    if(!vis[i]){
      int id = i;
      vll vv;
      while(!vis[id]){
        vv.push_back(C[id]);
        vis[id] =1;
        id = P[id];
      }
      v.push_back(vv);
    }
  }
  ll ans = -INF;
  for(auto &it : v){
    for(ll i = 1;i <= min(n*1ll,k); ++i){
      ll tmp = k;
      k = i;
      ans = max(ans , solve(it));
      k = tmp;
    }
    for(ll i = k;i >= max(1ll, k-n);--i){
      ll tmp = k;
      k = i;
      ans = max(ans , solve(it));
      k = tmp;
    }
    ans = max(ans , solve(it)); 
  }
  cout << ans << endl;
  return 0;
}

