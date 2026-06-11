#include <bits/stdc++.h>
using namespace std;
#if __has_include(<boost/multiprecision/cpp_int.hpp>)
	#include <boost/multiprecision/cpp_int.hpp>
	#include <boost/multiprecision/cpp_dec_float.hpp>
	using bll = boost::multiprecision::cpp_int;
	using bdouble = boost::multiprecision::cpp_dec_float_100;
	using namespace boost::multiprecision;
#endif
#if __has_include(<boost/stacktrace.hpp>)
	#define BOOST_STACKTRACE_USE_ADDR2LINE
	#define BOOST_STACKTRACE_ADDR2LINE_LOCATION /usr/local/opt/binutils/bin/addr2line
	#define _GNU_SOURCE 1
	#include <boost/stacktrace.hpp>
#endif
#ifdef LOCAL_TEST
	namespace std {
		template<typename T> class dvector : public std::vector<T> {
		public:
			dvector() : std::vector<T>() {}
			explicit dvector(size_t n, const T& value = T()) : std::vector<T>(n, value) {}
			dvector(const std::vector<T>& v) : std::vector<T>(v) {}
			dvector(const std::initializer_list<T> il) : std::vector<T>(il) {}
			dvector(const std::string::iterator first, const std::string::iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::iterator first, const typename std::vector<T>::iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::reverse_iterator first, const typename std::vector<T>::reverse_iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::const_iterator first, const typename std::vector<T>::const_iterator last) : std::vector<T>(first, last) {}
			dvector(const typename std::vector<T>::const_reverse_iterator first, const typename std::vector<T>::const_reverse_iterator last) : std::vector<T>(first, last) {}
			T& operator[](size_t n) {
				try { return this->at(n); } catch (const std::exception& e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; return this->at(n); }
			}
			const T& operator[](size_t n) const {
				try { return this->at(n); } catch (const std::exception& e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; return this->at(n); }
			}
		};
	}
	class dbool {
	private:
		bool boolvalue;
	public:
		dbool() : boolvalue(false) {}
		dbool(bool b) : boolvalue(b) {}
		operator bool&() { return boolvalue; }
		operator const bool&() const { return boolvalue; }
	};
	#define vector dvector
	#define bool dbool
#endif
#ifdef LOCAL_DEV
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<T>& v) {
		for (size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::vector<std::vector<T>>& vv) {
		s << "\\\n"; for (size_t i = 0; i < vv.size(); ++i){ s << vv[i] << "\n"; } return s; }
	template<typename T> std::ostream& operator<<(std::ostream& s, const std::deque<T>& v) {
		for (size_t i = 0; i < v.size(); ++i){ s << v[i]; if (i < v.size() - 1) s << "\t"; } return s; }
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
	class SIGFPE_exception : std::exception {};
	class SIGSEGV_exception : std::exception {};
	void catch_SIGFPE([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGFPE_exception(); }
	void catch_SIGSEGV([[maybe_unused]] int e) { std::cerr << boost::stacktrace::stacktrace() << '\n'; throw SIGSEGV_exception(); }
	signed convertedmain();
	signed main() { signal(SIGFPE, catch_SIGFPE); signal(SIGSEGV, catch_SIGSEGV); return convertedmain(); }
	#define main() convertedmain()
	void debug_impl() { std::cerr << '\n'; }
	template<typename Head, typename... Tail> void debug_impl(Head head, Tail... tail) { std::cerr << " " << head << (sizeof...(tail) ? "," : ""); debug_impl(tail...); }
	#define debug(...) do { std::cerr << "(" << #__VA_ARGS__ << ") ="; debug_impl(__VA_ARGS__); } while (false)
#else
	#define debug(...) do {} while (false)
#endif
//#define int long long
using ll = long long;
//constexpr int INF = (ll)1e9 + 7;//INT_MAX=(1<<31)-1=2147483647
constexpr ll INF = (ll)1e18;//(1LL<<63)-1=9223372036854775807
constexpr ll MOD = (ll)1e9 + 7;
constexpr double EPS = 1e-9;
constexpr ll dx[4] = {1, 0, -1, 0};
constexpr ll dy[4] = {0, 1, 0, -1};
constexpr ll dx8[8] = {1, 0, -1, 0, 1, 1, -1, -1};
constexpr ll dy8[8] = {0, 1, 0, -1, 1, -1, 1, -1};
#define rep(i, n)   for(ll i=0, i##_length=(n); i< i##_length; ++i)
#define repeq(i, n) for(ll i=1, i##_length=(n); i<=i##_length; ++i)
#define rrep(i, n)   for(ll i=(n)-1; i>=0; --i)
#define rrepeq(i, n) for(ll i=(n)  ; i>=1; --i)
#define all(v) (v).begin(), (v).end()
#define rall(v) (v).rbegin(), (v).rend()
void p() { std::cout << '\n'; }
template<typename Head, typename... Tail> void p(Head head, Tail... tail) { std::cout << head << (sizeof...(tail) ? " " : ""); p(tail...); }
template<typename T> inline void pv(std::vector<T>& v) { for(ll i=0, N=v.size(); i<N; i++) std::cout << v[i] << " \n"[i==N-1]; }
template<typename T> inline bool chmax(T& a, T b) { return a < b && (a = b, true); }
template<typename T> inline bool chmin(T& a, T b) { return a > b && (a = b, true); }
template<typename T> inline void uniq(std::vector<T>& v) { v.erase(std::unique(v.begin(), v.end()), v.end()); }

/*-----8<-----template-----8<-----*/

template<typename T>
class Imos {
public:
	//vectorの要素数
	ll size;
	//累積和したvector
	vector<T> rui;

	Imos(ll size) : size(size), rui(size, 0) {}

	//[l, r)の範囲に val を加算する
	void add(ll l, ll r, T val) {
		if(l == r || l >= size) return;
		l = clamp(l, 0LL, size-1);
		rui[l] += val;
		if(r < size) rui[r] -= val;
	}

	void build() {
		for (ll i = 1; i < size; ++i) {
			rui[i] += rui[i-1];
		}
	}

	// ruiの[l, r)に対して関数fを適用した結果を返却する
	template<typename F>
	T query(ll l, ll r, F &f) {
		T val = rui[l];
		for (ll i = l+1; i < r; ++i) {
			val = f(val, rui[i]);
		}
		return val;
	}

	// ruiの全域に対して関数fを適用した結果を返却する
	template<typename F>
	T query(F &f) {
		return query(0, size, f);
	}
};

/*-----8<-----library-----8<-----*/
 
void solve() {
	ll N,K;
	cin>>N>>K;
	vector<ll> a(N);
	rep(i,N)cin>>a[i];

	Imos<ll> imos(N);
	rep(i,N)imos.add(i-a[i], i+a[i]+1, 1);
	imos.build();
	debug(imos.rui);
	rep(_,K-1){
		Imos<ll> imos2(N);
		rep(i,N)imos2.add(i-imos.rui[i], i+imos.rui[i]+1, 1);
		imos2.build();
		debug(imos2.rui);
		if([&]{
			rep(i,N)if(imos.rui[i]!=imos2.rui[i])return false;
			return true;
		}()){
			break;
		}
		imos=imos2;
	}
	pv(imos.rui);
}

signed main() {
	solve();
	return 0;
}
