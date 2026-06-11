#include "bits/stdc++.h"
using namespace std;
using     ll=long long;
using    vll=vector<   ll>;
using   vvll=vector<  vll>;
using  vvvll=vector< vvll>;
using vvvvll=vector<vvvll>;
constexpr ll INF = 1LL << 60;
struct Fast{ //cin,cout高速化のおまじない＋桁数指定
	Fast(){ cin.tie(0); ios::sync_with_stdio(false); cout << fixed << setprecision(std::numeric_limits<double>::max_digits10); }
} fast;
#define REPS(i, S, E) for (ll i = (S); i <= (E); i++)
#define REP(i, N) REPS(i, 0, (N)-1)
#define DEPS(i, S, E) for (ll i = (E); i >= (S); i--)
#define DEP(i, N) DEPS(i, 0, (N)-1)
#define EACH(e, v) for (auto&& e : v)
#define rep(i, S, E)  for (ll i = (S); i <= (E); i++)
#define dep(i, E, S)  for (ll i = (E); i >= (S); i--)
#define each(e, v) for (auto&& e : v)
#define ALL(v) (v).begin(), (v).end()
#define RALL(v) (v).rbegin(), (v).rend()
template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }
template<class T> inline T MaxE(vector<T>&v,ll S,ll E){ T m=v[S]; rep(i,S,E)chmax(m,v[i]); return m; }
template<class T> inline T MinE(vector<T>&v,ll S,ll E){ T m=v[S]; rep(i,S,E)chmin(m,v[i]); return m; }
template<class T> inline T MaxE(vector<T> &v) { return MaxE(v,0,(ll)v.size()-1); }
template<class T> inline T MinE(vector<T> &v) { return MinE(v,0,(ll)v.size()-1); }
template<class T> inline T Sum(vector<T> &v,ll S,ll E){ T s=T(); rep(i,S,E)s+=v[i]; return s; }
template<class T> inline T Sum(vector<T> &v) { return Sum(v,0,v.size()-1); }
template<class T> inline ll sz(T &v){ return (ll)v.size(); }
template<class T> inline T POW(T a, ll n){ T r=1; for (; n>0; n>>=1, a*=a){ if (n&1)r*=a; } return r; }
inline ll POW(int a, ll n){ return POW((ll)a, n); }
inline ll CEIL(ll a, ll b){ return (a+b-1)/b; }



void solve()
{
	vector<vector<ll>> a(3,vector<ll>(3));
	rep(i,0,3-1)rep(j,0,3-1){ ll a_; cin>>a_; a[i][j]=a_; }
	ll n;  cin >> n;
	vector<ll> b(n);  rep(i,0,n-1){ ll b_; cin>>b_; b[i]=b_; }

	vvll p(3,vll(3));
	rep(i,0,2){
		rep(j,0,2){
			if (find(ALL(b),a[i][j])!=b.end()){
				p[i][j]=1;
			}
		}
	}

	rep(i,0,2){
		bool isall=true;
		rep(j,0,2) if (!(p[i][j]==1)) {isall=false; break;}
		if (isall){
			cout << "Yes" << '\n'; return;
		}
	}
	rep(i,0,2){
		bool isall=true;
		rep(j,0,2) if (!(p[j][i]==1)) {isall=false; break;}
		if (isall){
			cout << "Yes" << '\n'; return;
		}
	}
	{
		bool isall=true;
		rep(i,0,2) if (!(p[i][i]==1)) { isall=false; break; }
		if (isall){
			cout << "Yes" << '\n'; return;
		}
	}
	{
		bool isall=true;
		rep(i,0,2) if (!(p[i][2-i]==1)) { isall=false; break; }
		if (isall){
			cout << "Yes" << '\n'; return;
		}
	}
	cout << "No" << '\n';
}


int main(){
#if 1
	solve();
#else
	ll t;  cin >> t;
	rep(i, 0, t-1){
		solve();
	}
#endif
	return 0;
}
