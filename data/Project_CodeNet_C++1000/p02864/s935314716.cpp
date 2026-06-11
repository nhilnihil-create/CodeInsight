#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using vll = std::vector<ll>;
using vvll = std::vector<vll>;
using vvvll = std::vector<vvll>;
using dd = double;
using vdd = std::vector<dd>;
using vvdd = std::vector<vdd>;
using vvvdd = std::vector<vvdd>;

constexpr ll INF = 1LL << 60;
constexpr dd EPS = 1e-11;

typedef std::numeric_limits< double > dbl;

//cin,cout高速化のおまじない＋桁数指定
struct Fast{
	Fast(){
		cin.tie(0);
		ios::sync_with_stdio(false);
		cout << fixed << setprecision(std::numeric_limits<double>::max_digits10);
	}
} fast;

#define REPS(i, S, E) for (ll i = (S); i <= (E); i++)
#define REP(i, N) REPS(i, 0, N-1)
#define DEPS(i, S, E) for (ll i = (E); i >= (S); i--)
#define DEP(i, N) DEPS(i, 0, N-1)
#define EACH(e, v) for (auto&& e : v)

template<class T> inline bool chmax(T &a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T &a, T b) { if (a > b) { a = b; return true; }return false; }
template<class T> inline T MaxE(vector<T>&v,ll S,ll E){T m=v[S]; REPS(i,S,E)chmax(m,v[i]); return m;}//v[S]～v[E]の最大値
template<class T> inline T MinE(vector<T>&v,ll S,ll E){T m=v[S]; REPS(i,S,E)chmin(m,v[i]); return m;}//v[S]～v[E]の最小値
template<class T> inline T MaxE(vector<T> &v, ll N) { return MaxE(v, 0, N - 1); } //先頭N個中の最大値
template<class T> inline T MinE(vector<T> &v, ll N) { return MinE(v, 0, N - 1); }
template<class T> inline T MaxE(vector<T> &v) { return MaxE(v, (ll)v.size()); }
template<class T> inline T MinE(vector<T> &v) { return MinE(v, (ll)v.size()); }
template<class T> inline ll MaxI(vector<T>&v,ll S,ll E){ll m=S; REPS(i,S,E){if(v[i]>v[m])m=i;} return m;}
template<class T> inline ll MinI(vector<T>&v,ll S,ll E){ll m=S; REPS(i,S,E){if(v[i]<v[m])m=i;} return m;}
template<class T> inline ll MaxI(vector<T> &v, ll N) { return MaxI(v, 0, N - 1); }
template<class T> inline ll MinI(vector<T> &v, ll N) { return MinI(v, 0, N - 1); }
template<class T> inline ll MaxI(vector<T> &v) { return MaxI(v, (ll)v.size()); }
template<class T> inline ll MinI(vector<T> &v) { return MinI(v, (ll)v.size()); }
template<class T> inline T Sum(vector<T> &v, ll S, ll E){ T s=v[S]; REPS(i, S+1, E)s+=v[i]; return s; }
template<class T> inline T Sum(vector<T> &v, ll N) { return Sum(v, 0, N - 1); }
template<class T> inline T Sum(vector<T> &v) { return Sum(v, v.size()); }

template<class T=ll> inline vector<T> cinv(ll N){ vector<T> v(N); REP(i, N)cin>>v[i]; return move(v);}
template<class T=ll, class S=ll> inline vector<pair<T, S>> cinv2(ll N){
	vector<pair<T, S>> v(N); REP(i,N){cin>>v[i].first>>v[i].second;} return move(v); }
template<class T=ll,class S=ll,class R=ll> inline vector<tuple<T, S, R>> cinv3(ll N){
	vector<tuple<T,S,R>> v(N); REP(i,N){cin>>get<0>(v[i])>>get<1>(v[i])>>get<2>(v[i]);} return move(v);}
template<class T> inline void coutv(vector<T> &v, char deli=' '){
	ll N=(ll)v.size(); REP(i,N){cout << v[i] << ((i==N-1)?'\n':deli);} }


ll N, K;
vvll dp;
vll H;

ll &Dp(ll i, ll k){
	static ll zero = 0;
	static ll inv = INF;
	if (k<0) return inv;
	if (i<0) return zero;
	return dp[i][k];
}

ll &HH(ll i){
	static ll zero = 0;
	if (i<0) return zero;
	if (N <= i) return zero;
	return H[i];
}



void solve()
{
	cin >> N >> K;
	H = cinv(N);

	dp.resize(N+1, vll(K+1, INF));
	REP(i, N+1){
		REPS(k, 0, K){
			REPS(s, 0, K){
				chmin( Dp(i, k), Dp(i-s-1, k-s)+ max(0LL, HH(i)-HH(i-s-1)) );
			}
		}
	}

	cout << MinE(dp[N]) << '\n';
}

int main(){
	solve();
	return 0;
}
