#pragma GCC optimize(2)
#pragma GCC optimize("Ofast")
#include<iostream>
#include <algorithm>
#include <cmath>
#include <iterator>
#include <cstring>
#include <utility>
#include <cstdio>
#include <iomanip>
#include <sstream>
#include <map>
#include <unordered_map>
#include <vector> 
#include <bitset>
#include <cctype>
#include <set>
#include <stack>
#include <queue>
#include <fstream>
#include <numeric>
#include <random>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int MAXN = 100005;
const int MAXM = 50005;
const double EPS = 1e-8;
const int MOD = 1e9+7;

#define MP make_pair
#define INF 0x3f3f3f3f
#define closeSync ios::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define mst(X,Y) memset(X,Y,sizeof(X)) 
#define rep(i, a, n) for (int i=(a); i<=(n); i++)
#define per(i, a, n) for (int i=(a); i>=(n); i--)
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
void debug_out() { cerr << endl; }
template <typename T> inline T max(T a, T b, T c) { return max(max(a, b), c); }
template <typename Head, typename... Tail>void debug_out(Head H, Tail... T) { cerr << " " << to_string(H);    debug_out(T...);}



void solve()
{
	int n;
	cin >> n;
	vector<vector<ll>>v (5);
	rep (i,1,n)
	{
		ll x,y;
		cin >> x >> y;
		v[1].push_back(x + y);
		v[2].push_back(x - y);
		v[3].push_back(-x + y);
		v[4].push_back(-x - y);
	}
	rep (i,1,4)
		sort(v[i].begin(),v[i].end());		
	ll ans = 0;
	rep (i,1,4)
		ans = max(ans,v[i][n-1] - v[i][0]);
	cout << ans << endl;
}


int main()
{closeSync;
#ifdef DEBUG
	//freopen("C:/Users/86159/Desktop/a2.in.txt", "r", stdin);
	//freopen("C:/Users/86159/Desktop/output.txt", "w", stdout);
#endif
	//clock_t c1 = clock();

	solve();

    //cerr << "Time:" << clock() - c1 << "ms" <<endl;
    return 0;
}