#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

#define REP(i,n) for(long long i = 0; i < (n); i++)
#define FOR(i, m, n) for(long long i = (m);i < (n); ++i)
#define ALL(obj) (obj).begin(),(obj).end()
#define SPEED cin.tie(0);ios::sync_with_stdio(false);

template<class T> using V = vector<T>;
template<class T, class U> using P = pair<T, U>;
template<class T> using PQ = priority_queue<T>;
template<class T> using PQR = priority_queue<T,vector<T>,greater<T>>;

constexpr long long MOD = (long long)1e9 + 7;
constexpr long long MOD2 = 998244353;
constexpr long long HIGHINF = (long long)1e18;
constexpr long long LOWINF = (long long)1e15;
constexpr long double PI = 3.1415926535897932384626433;

template <class T> vector<T> make_v(size_t N,T init){return vector<T>(N,init);}
template <class... T> auto make_v(size_t N,T... t){return vector<decltype(make_v(t...))>(N,make_v(t...));}
template <class T> void corner(bool flg, T hoge) {if (flg) {cout << hoge << endl; exit(0);}}
template <class T, class U>ostream &operator<<(ostream &o, const map<T, U>&obj) {o << "{"; for (auto &x : obj) o << " {" << x.first << " : " << x.second << "}" << ","; o << " }"; return o;}
template <class T>ostream &operator<<(ostream &o, const set<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const multiset<T>&obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr) o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
template <class T>ostream &operator<<(ostream &o, const vector<T>&obj) {o << "{"; for (int i = 0; i < (int)obj.size(); ++i)o << (i > 0 ? ", " : "") << obj[i]; o << "}"; return o;}
template <class T, class U>ostream &operator<<(ostream &o, const pair<T, U>&obj) {o << "{" << obj.first << ", " << obj.second << "}"; return o;}
template <template <class tmp>  class T, class U> ostream &operator<<(ostream &o, const T<U> &obj) {o << "{"; for (auto itr = obj.begin(); itr != obj.end(); ++itr)o << (itr != obj.begin() ? ", " : "") << *itr; o << "}"; return o;}
void print(void) {cout << endl;}
template <class Head> void print(Head&& head) {cout << head;print();}
template <class Head, class... Tail> void print(Head&& head, Tail&&... tail) {cout << head << " ";print(forward<Tail>(tail)...);}
template <class T> void chmax(T& a, const T b){a=max(a,b);}
template <class T> void chmin(T& a, const T b){a=min(a,b);}
void YN(bool flg) {cout << (flg ? "YES" : "NO") << endl;}
void Yn(bool flg) {cout << (flg ? "Yes" : "No") << endl;}
void yn(bool flg) {cout << (flg ? "yes" : "no") << endl;}


// Column_01Echelon_Formalize O(N)
vector<long long>  BinaryColumnEchelonFormalize(vector<long long> vec){
	for(int i = 59,idx = -1; 0 <= i; --i,idx = -1){
		sort(vec.begin(),vec.end(),greater<long long>());
		for(int j = 0,flg = 1; j < vec.size(); ++j,flg = 0){
			if( !((vec[j]>>i) & 1) ) continue;
			for(int k = 59; i < k; --k) if((vec[j]>>k) & 1) flg = 1;
			if(flg) continue;
			idx = j;
			break;
		}
		for(int j = 0; idx != -1 && j < vec.size(); ++j) if(idx != j && ((vec[j]>>i) & 1)) vec[j] ^= vec[idx];
	}

	return vec;
}

int main() {
	int N; cin >> N;
	vector<ll> A(N);
	for(int i = 0; i < N; ++i) cin >> A[i];
	ll L = 0,R = 0;
	for(int i = 0; i < N; ++i) L ^= A[i];
	for(int n = 0; n < 60; ++n) {
		int sum = 0;
		for(int i = 0; i < N; ++i) sum += ((A[i]>>n)&1);
		if(sum%2) {
			R ^= (1LL<<n);
			for(int i = 0; i < N; ++i) if((A[i]>>n)&1) A[i] ^= (1LL<<n);
		}
	}
	auto B = BinaryColumnEchelonFormalize(A);
	for(int i = 0; i < N; ++i) R ^= B[i];
	cout << R + (R^L) << endl;
	
	return 0;
}
