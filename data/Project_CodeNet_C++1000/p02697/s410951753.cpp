// By Mohit Gupta
#include <bits/stdc++.h>
using namespace std;
//DEBUG 
void debug_out() { cerr << endl; }
template <typename Head, typename... Tail>
void debug_out(Head H, Tail... T) {
  cerr << " " << to_string(H);
  debug_out(T...);
}
#define printint(v) copy(begin(v), end(v), ostream_iterator<int>(cout," "))
#define printintv(s,e) copy(s,e, ostream_iterator<int>(cout," "))
#define forstl(i,v) for(auto &i: v)
#define all(v) (v).begin(), (v).end()
#define forn(i,e) for(int i = 0; i < e; i++)
#define forsn(i,s,e) for(int i = s; i < e; i++)
#define rforn(i,s) for(int i = s; i >= 0; i--)
#define rforsn(i,s,e) for(int i = s; i >= e; i--)
#define clz(a) __builtin_clz(a) // count leading zeroes
#define ctz(a) __builtin_ctz(a) // count trailing zeroes
#define popc(a) __builtin_popcount(a) // count set bits (for ints only diff for ll)
//https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html for other in built
#define ln "\n"
#define dbg(x) cout<<#x<<" = "<<x<<ln
#define pb push_back
#define fi first
#define se second
#define IOS ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
typedef long long ll;
typedef pair<int,int> p32; 
typedef pair<ll,ll> p64;
typedef pair<double,double> pdd;
typedef vector<ll> v64;
typedef vector<int> v32;
typedef vector<vector<int> > vv32;
typedef vector<p64> vp64;
typedef vector<p32> vp32;
typedef map<int,int> m32;
#pragma GCC optimize ("-O2")
const int LIM = 5e5+5, MOD = 998244353;
int t,n,m,k,x,y;
 
 
int32_t main()
{
    IOS;
    cin>>n>>m;
    if(n%2==1){
      forsn(i,1,m+1){
        cout<<i<<" "<<n-i<<ln;
      }
    }
    else{
      int k=n/2;
      int l=k/2;
      int r=l+1;
      while(l>=1 && m){
        cout<<l<<" "<<r<<ln;
        l--;
        r++;
        m--;
      }
      l=k/2;
      r=l+2;
      while(r<=k && m){
        cout<<k+l<<' '<<k+r<<ln;
        l--;
        r++;
        m--;
      }
    }
}
