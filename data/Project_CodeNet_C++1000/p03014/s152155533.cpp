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
#include <functional>
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

	int h, w; cin >> h >> w;
	vector<string> grid(h); for (int i = 0; i <= h - 1; i++) cin >> grid[i];

	vector<vector<int>> rpref(h, vector<int>(w, 0));
	vector<vector<int>> rsuff(h, vector<int>(w, 0));
	vector<vector<int>> cpref(h, vector<int>(w, 0));
	vector<vector<int>> csuff(h, vector<int>(w, 0));

	for (int i = 0; i <= h - 1; i++) {
		rpref[i][0] = (grid[i][0] == '.');
		for (int j = 1; j <= w - 1; j++) if (grid[i][j] == '.') rpref[i][j] = rpref[i][j - 1] + 1;
	}

	for (int i = 0; i <= h - 1; i++) {
		rsuff[i][w - 1] = (grid[i][w - 1] == '.');
		for (int j = w - 2; j >= 0; j--) if (grid[i][j] == '.') rsuff[i][j] = rsuff[i][j + 1] + 1;
	}

	for (int j = 0; j <= w - 1; j++) {
		cpref[0][j] = (grid[0][j] == '.');
		for (int i = 1; i <= h - 1; i++) if (grid[i][j] == '.') cpref[i][j] = cpref[i - 1][j] + 1;
	}

	for (int j = 0; j <= w - 1; j++) {
		csuff[h - 1][j] = (grid[h - 1][j] == '.');
		for (int i = h - 2; i >= 0; i--) if (grid[i][j] == '.') csuff[i][j] = csuff[i + 1][j] + 1;
	}

	int ans = 0;
	for (int i = 0; i <= h - 1; i++) {
		for (int j = 0; j <= w - 1; j++) ans = max(ans, rpref[i][j] + rsuff[i][j] + cpref[i][j] + csuff[i][j] - 3 * (grid[i][j] == '.'));
	}
	cout << ans;

	return 0;
}