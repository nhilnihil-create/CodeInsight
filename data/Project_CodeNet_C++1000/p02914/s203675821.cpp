//atcoderstock
#include <bits/stdc++.h>
using namespace std;
#ifndef ONLINE_JUDGE
	#include <boost/multiprecision/cpp_int.hpp>
	#include <boost/multiprecision/cpp_dec_float.hpp>
	using bll = boost::multiprecision::cpp_int;
	using bdouble = boost::multiprecision::cpp_dec_float_100;
#endif
#ifdef LOCAL_DEV
	void debug_impl() { std::cerr << '\n'; }
	template<typename Head, typename... Tail> void debug_impl(Head head, Tail... tail) { std::cerr << " " << head << (sizeof...(tail) ? "," : ""); debug_impl(tail...); }
	#define debug(...) do { std::cerr << "(" << #__VA_ARGS__ << ") ="; debug_impl(__VA_ARGS__); } while (false)
#else
	#define debug(...) do {} while (false)
#endif
#ifdef LOCAL_TEST
	#define BOOST_STACKTRACE_USE_ADDR2LINE
	#define BOOST_STACKTRACE_ADDR2LINE_LOCATION /usr/local/opt/binutils/bin/addr2line
	#define _GNU_SOURCE
	#include <boost/stacktrace.hpp>
	namespace std {
		template<typename T> class dvector : public std::vector<T> {
		public:
			dvector() : std::vector<T>() {}
			explicit dvector(size_t n, const T& value = T()) : std::vector<T>(n, value) {}
			dvector(const std::vector<T>& v) : std::vector<T>(v) {}
			dvector(const std::initializer_list<T> il) : std::vector<T>(il) {}
			dvector(const typename std::vector<T>::iterator first, const typename std::vector<T>::iterator last) : std::vector<T>(first, last) {}
			dvector(const std::string::iterator first, const std::string::iterator last) : std::vector<T>(first, last) {}
			T& operator[](size_t n) {
				try { return this->at(n); } catch (const std::exception& e) {
					std::cerr << boost::stacktrace::stacktrace() << '\n'; return this->at(n);
				}
			}
			const T& operator[](size_t n) const {
				try { return this->at(n); } catch (const std::exception& e) {
					std::cerr << boost::stacktrace::stacktrace() << '\n'; return this->at(n);
				}
			}
		};
	}
	class dbool {
	private:
		bool boolvalue;
	public:
		dbool() : boolvalue(false) {}
		dbool(bool b) : boolvalue(b) {}
		dbool(const dbool& b) : boolvalue(b.boolvalue) {}
		operator bool&() { return boolvalue; }
		operator const bool&() const { return boolvalue; }
	};
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::dvector<T>& v) {
		for (size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::dvector<std::dvector<T>>& vv) {
		s << "\n"; for (size_t i = 0; i < vv.size(); ++i){ s << vv[i] << "\n"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::set<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::multiset<T>& se) {
		s << "{ "; for (auto itr = se.begin(); itr != se.end(); ++itr){ s << (*itr) << "\t"; } s << "}"; return s; }
	template <typename T, size_t N> std::ostream& operator<<(std::ostream& s, const std::array<T, N>& a) {
		s << "{ "; for (size_t i = 0; i < N; ++i){ s << a[i] << "\t"; } s << "}"; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::map<T1, T2>& m) {
		s << "{\n"; for (auto itr = m.begin(); itr != m.end(); ++itr){ s << "\t" << (*itr).first << " : " << (*itr).second << "\n"; } s << "}"; return s; }
	template<typename T1, typename T2> std::ostream& operator<<(std::ostream& s, const std::pair<T1, T2>& p) {
		return s << "(" << p.first << ", " << p.second << ")"; }
	#define vector dvector
	#define bool dbool
	class SIGFPE_exception : std::exception {};
	class SIGSEGV_exception : std::exception {};
	void catch_SIGFPE(int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGFPE_exception();	}
	void catch_SIGSEGV(int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGSEGV_exception(); }
	signed convertedmain();
	signed main() { signal(SIGFPE, catch_SIGFPE); signal(SIGSEGV, catch_SIGSEGV); return convertedmain(); }
	#define main() convertedmain()
#endif
//#define int long long
using ll = long long;
//constexpr int INF = 1e9;//INT_MAX=(1<<31)-1=2147483647
constexpr ll INF = (ll)1e18;//(1LL<<63)-1=9223372036854775807
constexpr ll MOD = 2;
constexpr double EPS = 1e-9;
constexpr ll dx[4] = {1LL, 0LL, -1LL, 0LL};
constexpr ll dy[4] = {0LL, 1LL, 0LL, -1LL};
constexpr ll dx8[8] = {1LL, 0LL, -1LL, 0LL, 1LL, 1LL, -1LL, -1LL};
constexpr ll dy8[8] = {0LL, 1LL, 0LL, -1LL, 1LL, -1LL, 1LL, -1LL};
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(ll i=1, i##_length=(n); i<=i##_length; ++i)
#define rrep(i, n)   for(ll i=(n)-1; i>=0; --i)
#define rrepeq(i, n) for(ll i=(n)  ; i>=1; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
void p() { std::cout << '\n'; }
template<typename Head, typename... Tail> void p(Head head, Tail... tail) { std::cout << head << (sizeof...(tail) ? " " : ""); p(tail...); }
template<typename T> inline void pv(std::vector<T>& v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template<typename T> inline T gcd(T a, T b) { return b ? gcd(b,a%b) : a; }
template<typename T> inline T lcm(T a, T b) { return a / gcd(a,  b) * b; }
template<typename T> inline bool chmax(T& a, T b) { return a < b && (a = b, true); }
template<typename T> inline bool chmin(T& a, T b) { return a > b && (a = b, true); }
template<typename T> inline void uniq(std::vector<T>& v) { v.erase(std::unique(v.begin(), v.end()), v.end()); }

/*-----8<-----template-----8<-----*/

// Bit Matrix
constexpr ll MAX_ROW = 64; // 式の数の最大値 問題に応じて変えること
constexpr ll MAX_COL = 1e5+1; // 変数の数の最大値 問題に応じて変えること
class BitMatrix {
public:
	ll H, W;
	bitset<MAX_COL> val[MAX_ROW];
	BitMatrix(ll m = 1, ll n = 1) : H(m), W(n) {}
	inline bitset<MAX_COL>& operator [] (ll i) { return val[i]; }
};
std::ostream& operator<<(std::ostream& s, BitMatrix& A) { 
	for(ll i=0; i<A.H; i++) for(ll j=0; j<A.W; j++) s << A[i][j] << "\t\n"[j==A.W-1];
	return s;
}

// F2(0,1しかないやつ)上において AX=b の解Xを求める
// 0 .. 0 1 の行 : 上位の行を成立させると、この行を成立させることはできない
// 0 .. 0 0 の行 : 上位の行を成立させると、自動でこの行も成立する
// http://drken1215.hatenablog.com/entry/2019/09/16/213700
BitMatrix gauss_jordan_F2(vector<vector<ll>> &A, vector<ll> &b) {
	BitMatrix X(A.size(), A[0].size()+1);
	for(ll i = 0; i < X.H; ++i)
		for(ll j = 0; j< X.W-1; ++j)
			X[i][j] = A[i][j];

	for(ll i = 0; i < X.H; i++)
		X[i][X.W-1] = b[i];
	
	vector<bool> used(X.H, false);
	for (ll col = 0; col < X.W-1; ++col) {
		ll pivot = -1;
		for (ll row = 0; row < X.H; ++row) {
			if (used[row]) continue;
			if (X[row][col]) {
				pivot = row;
				break;
			}
		}
		if (pivot == -1) continue;
		for (ll row = 0; row < X.H; ++row) {
			if (row != pivot && X[row][col]) X[row] ^= X[pivot];
		}
		used[pivot] = true;
	}

	return X;
}

/*-----8<-----library-----8<-----*/

inline ll up(ll bit, ll i) { return bit | (1LL<<i); }
inline ll down(ll bit, ll i) { return bit & ~(1LL<<i); }
inline ll inverse(ll bit, ll i) { return bit ^ (1LL<<i); }
inline bool isup(ll bit, ll i) { return bit & (1LL<<i); }
inline bool isdown(ll bit, ll i) { return !(bit & (1LL<<i)); }
//__builtin_popcount(bit); -> bitの立っている個数を返す

void solve() {
	ll N;
	cin>>N;
	vector<ll> z(N);
	rep(i,N)cin>>z[i];

	ll size=60;
	vector<ll> count(size,0);
	rep(i,N){
		rep(j,size){
			if(isup(z[i],j))count[j]++;
		}
	}

	//理想形の方程式を立てる(どのビットも1にできたらうれしい)
	vector<vector<ll>> a;
	vector<ll> b;
	map<ll,ll> m;
	ll c=0;
	ll ans=0;
	rrep(bit,size){
		if(count[bit]==0){
			continue;
		}
		if(count[bit]%2==1){
			ans+=1LL<<bit;
			continue;
		}

		m[c]=bit;c++;
		vector<ll> v(N,0);
		rep(i,N){
			if(isup(z[i],bit))v[i]=1;
		}
		a.emplace_back(v);
		b.emplace_back(1);
	}
	
	if(a.size()==0){
		p(ans);return;
	}

	BitMatrix x = gauss_jordan_F2(a,b);

	rrep(i,a.size()){
		if([&]{
			rep(j,x.W-1)if(x[i][j])return true;
			if(x[i][x.W-1]==0)return true;
			return false;
		}()){
			//成立していれば加算
			ans+=1LL<<(1+m[i]);
		}
	}
	p(ans);
}

//https://atcoder.jp/contests/abc141/tasks/abc141_f
signed main() {
	solve();
	return 0;
}
