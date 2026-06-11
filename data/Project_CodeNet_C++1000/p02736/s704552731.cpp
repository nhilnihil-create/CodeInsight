#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#pragma warning(disable : 4996)
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
#include<unordered_map>
#include<unordered_set>
#include<time.h>
#include<random>
#include<array>


using namespace std;

#define REP(i, n) for(int i = 0;i < n;++i)
#define REPR(i, n) for(int i = n-1;i >= 0;--i)
#define FOR(i, m, n) for(int i = m;i < n;++i)
#define FORR(i, m, n) for(int i = m-1;i >= n;--i)
#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define REVERSE(v,n) reverse(v,v+n);
#define VREVERSE(v) reverse(v.begin(), v.end())
#define ll long long
#define print(x) cout<<(x)<<'\n'
#define pe(x) cout<<(x)<<" "
#define DEBUG(x) cout<<#x<<": "<<x<<endl
#define lb(v,n) lower_bound(v.begin(), v.end(), (n))
#define ub(v,n) upper_bound(v.begin(), v.end(), (n))
#define int long long
//#define double long double
#define all(x) (x).begin(), (x).end()
#define print_space(v) REP(i,v.size())cout << v[i] << ((i == v.size() - 1) ? "\n" : " ")
template<typename T1, typename T2> inline void chmin(T1 & a, T2 b) { if (a > b) a = b; }
template<typename T1, typename T2> inline void chmax(T1& a, T2 b) { if (a < b) a = b; }
typedef pair<int, int>P;
typedef array<int, 3> arr3;
std::random_device rd;
std::mt19937 mt(rd());
constexpr ll MOD = 998244353; constexpr int MAX = 2000020;
const double pi = acos(-1); constexpr double EPS = 1e-8;
constexpr ll INF = 1e18;

ll fac[2000020];
void init() {
	FOR(i, 1, 2000001) {
		int x = i;
		int res = 0;
		while (x % 2 == 0) {
			res++;
			x /= 2;
		}
		fac[i] = fac[i - 1] + res;
	}
}
int calc(vector<int>&v,int N) {
	init();
	bool found1 = false;
	REP(i, N)if (v[i] == 1)found1 = true;
	if (!found1) {
		REP(i, N)if (v[i] == 2)v[i] = 1;
	}
	int sum = 0;
	REP(i, N) {
		if (v[i] == 0||v[i]==2)continue;
		int cnt = fac[N - 1];
		cnt -= (fac[N - i - 1] + fac[i]);
		if (cnt == 0)sum += 1;
		sum %= 2;
	}
	if (sum) {
		if (found1)return 1;
		else return 2;
	}
	else return 0;
}

void solve() {
	int N; cin >> N;
	string S; cin >> S;
	vector<int>v;
	REP(i, N - 1) {
		v.push_back(abs(S[i] - S[i + 1]));
	}
	//print_space(v);
	print(calc(v, N - 1));
}

signed main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	//int q; cin >> q;
	//while (q--)
	solve();
}

