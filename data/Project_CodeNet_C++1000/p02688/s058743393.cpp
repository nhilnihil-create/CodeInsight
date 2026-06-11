#include <bits/stdc++.h>
#define MAX 1000000
#define MOD 1e9
#define pb push_back
#define pairs pair<int, int>
#define vi vector<int>
#define vb vector<bool>
#define vii vector<pairs>
#define lb lower_bound
#define ub upper_bound
#define ll long long
#define endl '\n'
using namespace std;
/* ----------------------------------------------------------------------------------- */

#define FastInput ios_base::sync_with_stdio(false), cin.tie(NULL);
#define all(x) x.begin(), x.end()
#define read(x) freopen(x, "r", stdin)
#define write(x) freopen(x, "w", stdout)
#define rep(i, a, n) for (int i = a; i < n; i++)
#define REP(i, a, n) for (int i = a; i <= n; i++)
#define inputArray(a,n) rep(i, 0, n) cin >> a[i];
#define copyArray(a,temp,n) rep(i, 0, n) temp[i]=a[i];
#define printArray(a,n) rep(i, 0, n) cout << a[i] << " "; cout << endl;

/* ----------------------------------------------------------------------------------- */

#define Cases  cout << "Case " << ++Case << ": ";
#define __test int tt; int Case=0; cin >> tt; while(tt--)

#define dbgA2(A, n, m) {cout<<"--> "<<#A<<" = \n";rep(i, 0, n){rep(j, 0, n){cout<<A[i][j]<<" ";}cout<<"\n";}cout<<"\n";}
#define dbgA(A, n) {cout<<" --> "<<#A<<" = (";rep(i, 0, n)cout<<A[i]<<" ";cout<<")\n";}
#define dbg(args...) {string sss(#args);sss+=',';cout<<" --> ";debugger::call(all(sss), args);cout<<"\n";}

/* ----------------------------------------------------------------------------------- */

ll gcd(ll n, ll m) { return m ? gcd(m, n % m) : n; }
ll lcm(ll n, ll m) { return n / gcd(n, m) * m; }

struct debugger {
	typedef string::iterator si;
	static void call(si it, si ed) {}
	template<typename T, typename ... aT>
	static void call(si it, si ed, T a, aT... rest) {
		string b;
		for(; *it!=','; ++it)
			if(*it!=' ')
				b+=*it;
		cout << b << "=" << a << " ";
		call(++it, ed, rest...);
	}
};

/* ----------------------------------------------------------------------------------- */

int n, k;
vector<int> d;
vector<vector<int>> a;

void input() {
	cin >> n >> k;
	d.resize(k);
	a.resize(k, vector<int>());

	for (int i = 0; i < k; i++) {
		cin >> d[i];
		a[i].resize(d[i]);
		for (int j = 0; j < d[i]; j++) {
			cin >> a[i][j];
		}
	}
}

void solve() {
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		bool have = false;
		for(auto v : a) {
			for (auto p : v) {
				if (p == i) {
					have = true;
				}
			}
		}
		if(!have) {
			ans++;
		}
	}
	cout << ans << endl;
}

int main() {
	input();
	solve();

	// __test {
	// 	solve();
	// }
}