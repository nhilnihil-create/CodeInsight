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
#define For(i,n) for(int i=0;i<(int)n;++i)
#define Rev(i,n) for(int i=(int)n-1;i>=0;--i)
#define Rep(i,n) for(int i=1;i<=(int)n;++i)
typedef vector<int> vi;
typedef pair<int,int> pii;
typedef pair<pii,int> ppi;
typedef vector<pii> vpi;
#define fio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define mp make_pair
const int mod = 1e9;
// inline void modadd(int &a,int &b){a+=b;if(a>=mod)a-=mod;} 
const int N = 2e5 + 100;

ll A[N];

int main(){
  fio; cout<<fixed<<setprecision(25);	
  int n, k; cin >> n >> k;
  ll mx = 0;
  for(int i = 1;i <= n; ++i){
    cin >> A[i];
    mx = max(mx , A[i]);
  }
  vector<int> v;
  v.pb(1);
  for(int i = 0; i < 30 ; ++i) v.pb(2*v.back());
  //cout << v << endl;

  ll lo = 1, hi = mx , ans = mx; 
  while(lo <= hi){
    ll m = (lo+hi)>>1;
    ll res = 0;
    //cout << m << endl;
    for(int i =1 ;i <= n ; ++i){
      //(m-1,m] range of log
      ll lft = (A[i]+m-1)/m;
      res += lft-1;
      //res += lower_bound(all(v) , lft) - v.begin();
      //cout << lft <<  endl;
    }

    if(res <= k){
      ans = m;
      hi = m-1;
    }
    else{
      lo =m+1;
    }
  }
  cout << ans << endl;






  return 0;
}
