// By Mohit Gupta
#include <bits/stdc++.h>
using namespace std;
#define printint(v) copy(begin(v), end(v), ostream_iterator<int>(cout," "))
#define printintv(s,e) copy(s,e, ostream_iterator<int>(cout," "))
#define forstl(i,v) for(auto &i: v)
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
#define mp make_pair
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
 
 
int main()
{
	IOS;
	int c;
	cin>>n>>k>>c;
	string str;
	cin>>str;
	v32 a(n+1);
	forsn(i,1,n+1){
		if(str[i-1]=='o') a[i]=1;
		else a[i]=0;
	}
	v32 l,r;
	int prev=-1;
	forsn(i,1,n+1){
		if(a[i]){
			if(prev==-1 || i-prev-1>=c)
				l.pb(i),prev=i;
		}
	}
	prev=-1;
	for(int i=n;i>=1;i--){
		if(a[i]){
			if(prev==-1 || prev-i-1>=c)
				r.pb(i),prev=i;
		}
	}
	// reverse(r.begin(),r.end());
	v32 rn;
	for(int i=k-1;i>=0;i--){
		rn.pb(r[i]);
	}
	forn(i,k){
		if(l[i]==rn[i]) cout<<l[i]<<ln;
	}
}
