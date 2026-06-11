#include <bits/stdc++.h>
#define ADD(a, b) a = (a + ll(b)) % mod
#define MUL(a, b) a = (a * ll(b)) % mod
#define MAX(a, b) a = max(a, b)
#define MIN(a, b) a = min(a, b)
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define rer(i, a, b) for(int i = int(a) - 1; i >= int(b); i--)
#define all(a) (a).begin(), (a).end()
#define sz(v) (int)(v).size()
#define pb push_back
#define sec second
#define fst first
#define debug(fmt, ...) Debug(__LINE__, ":", fmt, ##__VA_ARGS__)
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pi;
typedef pair<ll, ll> pl;
typedef pair<int, pi> ppi;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<vl> mat;
typedef complex<double> comp;
void Debug() {cerr << '\n'; }
template<class FIRST, class... REST>void Debug(FIRST arg, REST... rest){
	cerr<<arg<<" ";Debug(rest...);}
template<class T>ostream& operator<<(ostream& out,const vector<T>& v) {
	out<<"[";if(!v.empty()){rep(i,0,sz(v)-1)out<<v[i]<<", ";out<<v.back();}out<<"]";return out;}
template<class S, class T>ostream& operator<<(ostream& out,const pair<S, T>& v){
	out<<"("<<v.first<<", "<<v.second<<")";return out;}
const int MAX_N = 500010;
const int MAX_V = 100010;
const double eps = 1e-6;
const ll mod = 1000000007;
const int inf = 1 << 30;
const ll linf = 1LL << 60;
const double PI = 3.14159265358979323846;
mt19937 rng; //use it by rng() % mod, shuffle(all(vec), rng)
///////////////////////////////////////////////////////////////////////////////////////////////////

void edge(int a, int b) {
	cout << a << " " << b << "\n";
}
int N;

void solve() {
	cin >> N;
	if(N == 1 || N == 2) {
		cout << "No\n";
	}
	else {
		if(N % 4 == 3) {
			cout << "Yes\n";
			rep(i, 1, 2 * N) {
				edge(i, i + 1);
			}
		}
		else if(N % 4 == 1) {
			cout << "Yes\n";
			int n = N - 2;

			vector<int> vec;

			rep(i, 1, n + 1) vec.pb(i);
			rep(i, 1, n + 1) vec.pb(i + N);
			rep(i, 0, sz(vec) - 1) edge(vec[i], vec[i + 1]);

			edge(n + 1, n + 2);
			edge(n + 2, 1);
			edge(1, n + 1 + N);
			edge(n + 1 + N, n + 2 + N);
		}
		else if(N % 4 == 2) {

			cout << "Yes\n";
			int n = N - 3;

			vector<int> vec;

			rep(i, 1, n + 1) vec.pb(i);
			rep(i, 1, n + 1) vec.pb(i + N);
			rep(i, 0, sz(vec) - 1) edge(vec[i], vec[i + 1]);
			edge(n + 3, n + 1);
			edge(n + 1, 2);
			edge(2, n + 3 + N);
			edge(n + 3 + N, n + 1 + N);
			edge(n + 1, n + 2);
			edge(3, n + 2 + N);
		}
		else {
			if(__builtin_popcount(N) == 1) {
				cout << "No\n";
			}
			else {
				cout << "Yes\n";
				vector<int> vec;
				int a = 1;
				while(!(a & N)) a *= 2;
				int b = N ^ a;
				vec.pb(a);
				vec.pb(b);
				for(int i = 1; i <= N - 1; i++) {
					if(i != a && i != b) vec.pb(i);
				}
				vec.pb(a + N);
				vec.pb(b + N);
				for(int i = 1; i <= N - 1; i++) {
					if(i != a && i != b) vec.pb(i + N);
				}
				rep(i, 0, sz(vec) - 1) edge(vec[i], vec[i + 1]);
				edge(N, a);
				edge(b, N + N);
			}
		}
	}
}

uint32_t rd() {
	uint32_t res;
#ifdef __MINGW32__
	asm volatile("rdrand %0" :"=a"(res) ::"cc");
#else
	res = std::random_device()();
#endif
	return res;
}

int main() {
#ifndef LOCAL
	ios::sync_with_stdio(false);
    cin.tie(0);
#endif
    cout << fixed;
	cout.precision(20);
    cerr << fixed;
	cerr.precision(6);
	rng.seed(rd());
#ifdef LOCAL
	//freopen("in.txt", "wt", stdout); //for tester
    freopen("in.txt", "rt", stdin);
#endif	
	solve();
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << " s.\n";
	return 0;
}

