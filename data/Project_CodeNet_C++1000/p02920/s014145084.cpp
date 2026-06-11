//#pragma GCC optimize ("-O3","unroll-loops")
#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>


#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end());
#define ll long long
#define pb(a) push_back(a)
#define m0(x) memset(x,0,sizeof(x))
#define print(x) cout<<x<<'\n';
#define pe(x) cout<<x<<" ";
#define lb(v,n) lower_bound(v.begin(), v.end(), n);
#define ub(v,n) upper_bound(v.begin(), v.end(), n);
//#define int long long
#define all(x) (x).begin(), (x).end()
//#define double long double

using namespace std;

template<class T> inline bool chmin(T& a, T b) {
	if (a > b) {
		a = b;
		return true;
	}
	return false;
}
template<class T> inline bool chmax(T& a, T b) {
	if (a < b) {
		a = b;
		return true;
	}
	return false;
}

const int MOD = 1e9 + 7;
const ll INF = 1e17;
const int INT_INF = 1e9;
const double pi = acos(-1);
const double EPS = 1e-10;
typedef pair<int, int>P;
const int MAX = 200020;




signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);

	int N; cin >> N;
	vector<int>v;
	multiset<int>rem;
	REP(i, (1 << N)) {
		int x; cin >> x;
		v.pb(x);
		rem.insert(x);
	}
	//print(*rem.end());
	auto itr = rem.end(); itr--;
	multiset<int>used;
	used.insert(*itr);
	rem.erase(itr);
	int cnt = 1;
	int c = 0;
	REP(i, N) {
		auto itr = used.end();
		itr--;
		vector<int>err;
		auto itr_rem = rem.end();
		REP(j, used.size()) {
			bool done = false;
			int irr;
			while (!done) {
				if (itr_rem == rem.begin()) {
					print("No"); return 0;
				}
				itr_rem--;
				if (*itr_rem < *itr) {
					//print(c); c++;
					//pe(*itr); print(*itr_rem);
					done = true;
					itr--;
					err.pb(*itr_rem);
				}
				else {
					if (itr_rem == rem.begin()) {
						print("No");
						return 0;
					}
				}
			}
		}
		
		
		//pe(i)print(err.size());
		
		for (auto x : err) {
			//rem.erase(x);
			auto itr2 = rem.find(x);
			rem.erase(itr2);
			used.insert(x);
		}
		//for (auto x : used)pe(x); cout << endl;
		//for (auto x : rem)pe(x); cout << endl; cout << endl;
	}
	print("Yes");
}