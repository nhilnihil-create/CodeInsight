#include <map>
#include <set>
#include <list>
#include <cmath>
#include <deque>
#include <stack>
#include <queue>
#include <bitset>
#include <cstdio>
#include <string>
#include <vector>
#include <random>
#include <chrono>
#include <utility>
#include <numeric>
#include <cstdlib>
#include <cstring>
#include <climits>
#include <sstream>
#include <assert.h>
#include <iostream>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(bool x) {cerr << (x ? "true" : "false");}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}

template<typename T, typename V> void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i : x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";} void _print() {cerr << "]\n";}
template <typename T, typename... V>void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}
#ifdef HOME
#warning CHECK int:ll::INT_MAX:LLONG_MAX
#define maxn 20
#define debug(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define maxn 2000006
#define gcd __gcd
#define debug(x...)
#endif

#define ff first
#define endl '\n'
#define ss second
#define inf 0x3f3f3f3f
#define MOD 1000000007
#define PI 3.14159265358979323846264338327950L
#define f(i,x,n) for(int i=x;i<=n;i++)
#define fr(i,x,n) for(int i=x;i>=n;i--)
struct _ { ios_base::Init i; _() { ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL); } } _;

int dx[] = { -1, 0, 1, 0, -1, -1, 1, 1};
int dy[] = {0, 1, 0, -1, -1, 1, 1, -1};


int main() {

	long long  n, m; cin >> n >> m;
	vector<pair<bool, long long >> v(n + 1, {false, 0});

	for (long long  i = 1; i <= m; i++) {
		long long  p; cin >> p;
		string s; cin >> s;

		if (s == "AC") {
			if (v[p].ff == false) v[p].ff = true;
		}
		else {
			if (v[p].ff == false) v[p].ss++;
		}
	}

	long long  q1 = 0, q2 = 0;
	for (long long  i = 1; i <= n; i++) {
		q1 += (v[i].ff == true);
		if (v[i].ff == true) q2 += (v[i].ss);
	}

	cout << q1 << " " << q2;

	return 0;
}