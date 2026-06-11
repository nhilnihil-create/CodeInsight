#include <bits/stdc++.h>
using namespace std;
#define ull unsigned long long
#define MOD (int)(1e9+7)
#define ceil(x, y) (x%y==0? (x/y) : (x/y+1))
#define FOR(i, N) for(int i = 0; i < N; ++i)
#define FOR1(i, N) for(int i = 1; i <= N; ++i)
#define vi vector <int>
#define pii pair <int, int>
#define pb push_back
#define mp make_pair
#define ff first
#define ss second
#define mset(a, v) memset(a, v, sizeof(a))
#define all(v) (v).begin(), (v).end()
#define INF 2e9
#define EPS 1e-9
#define MAX 200009
#define PI 3.141592653589793238
#define int long long
/*#include <ext/pb_ds/assoc_container.hpp>
using namespace __gnu_pbds;
typedef cc_hash_table<int, int, hash<int>> ht; // while using, comment #define int long long  */

void __print(int x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif
using namespace std;
#define Q 50
int n, m, q;
int a[Q+1], b[Q+1], c[Q+1], d[Q+1];
int maxi = 0;
void fun(vector<int>& v, int i, int curr){
	/*i is length of currently generated sequence
	curr is the value above or = each element must be*/
	if(i == n){ // we have a sequence of length n in v
		int this_subs_score = 0;
		for(int j = 0; j < q; j++){
			if(v[b[j]] - v[a[j]] == c[j]){
				this_subs_score += d[j];
			}
		}
		maxi = max(maxi, this_subs_score);
	}
	else{
		for(int j = curr; j <= m; j++){
			v.pb(j);
			fun(v, i+1, j);
			v.pop_back();
		}
	}
}
int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    #ifndef ONLINE_JUDGE
    	freopen("in2.txt", "r", stdin);
    	freopen("out.txt", "w", stdout);
    #endif

	int T=1;
	//cin >> T;
	FOR1(tp, T)
	{
		//cout << "Case #" << tp << ": ";
		cin >> n >> m >> q;
		FOR(i, q) {
			cin >> a[i] >> b[i] >> c[i] >> d[i];
			a[i]--; b[i]--;
		}
		vector<int> v;
		fun(v, 0, 1);
		cout << maxi;
		cout << '\n';
	}
	return 0;
}