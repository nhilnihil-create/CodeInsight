#include <bits/stdc++.h>
using namespace std;
#define sync ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
#define rep(i,n) for(int i=0; i<int(n); ++i)
#define repp(i,a,n) for(int i=a; i<int(n); ++i)
#define sz(x) int((x).size())
#define pq priority_queue
#define pb push_back
#define eb emplace_back
#define mp make_pair

template<class T> std::ostream& operator<<(std::ostream& os, const std::vector<T> &input){for (auto const& i: input) {os << i << " ";}return os;}
template<class T> std::ostream& operator<<(std::ostream& os, const std::set<T> &input){for (auto const& i: input) {os << i << " ";}return os;}
template<class T> std::ostream& operator<<(std::ostream& os, const std::multiset<T> &input){for (auto const& i: input) {os << i << " ";}return os;}
template<class T, size_t n> std::ostream& operator<<(std::ostream& os, const std::array<T, n> &input){for (size_t i=0; i<n; ++i) {os << input[i] << " ";}return os;}
template<class T1, class T2> std::ostream& operator<<(std::ostream& os, const std::pair<T1,T2> &input){os << "(" << input.first << ", " << input.second << ')';return os;}
template<class T1, class T2> std::ostream& operator<<(std::ostream& os, const std::unordered_map<T1,T2> &input){for (auto const& i: input) {os << i << " ";}return os;}

void debug_out() { cerr << endl; }
template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) {cerr << " " << H;debug_out(T...);}
#ifdef LOCAL
#define dbg(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
#else
#define dbg(...) 42
#endif

double startTime;
double getCurrentTime(){return ((double)clock() - startTime) / CLOCKS_PER_SEC;}

typedef long long ll;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<int> vi;
typedef vector<pi> vp;
typedef vector<ll> vl;
typedef vector<vi> vvi;

// === temeplate ===

const int maxn = 50;

void solve(){
	int n,m,k; cin >> n >> m >> k;

	vi sumX(n,0), sumY(m,0);
	vvi Y(n, vi(0));
	rep(i,k){
		int x,y;cin >> x >> y; --x,--y;
		Y[x].pb(y);

		sumX[x] ++;
		sumY[y] ++;
	}

	int ans = 0;

	multiset<int> val; val.clear();

	rep(y,m) val.insert(sumY[y]);

	// dbg(val);

	rep(x,n){
		int sum = sumX[x];
		for(int y: Y[x]){
			val.erase(val.find(sumY[y]));
			sumY[y]--;
			val.insert(sumY[y]);
		}
		auto it = val.end();
		sum += *(--it);
		ans = max(ans, sum);
		for(int y: Y[x]){
			val.erase(val.find(sumY[y]));
			sumY[y]++;
			val.insert(sumY[y]);
		}
	}
	cout << ans << endl;
}

int main(){
    sync;
    int cas = 1;
    // cin >> cas;
    rep(ca, cas) solve();
    return 0;
}