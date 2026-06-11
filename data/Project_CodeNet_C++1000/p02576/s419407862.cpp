/*
	LINES :
		* easy
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int ui;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define pb push_back
#define F first
#define S second
#define WLL(t) while(t--)
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define STF(i, a, b) for(size_t i = a; i < b; i++)
#define RFOR(i, a, b) for(int i = a; i >= b; i--)
#define SRF(i, a, b) for(size_t i = a;i >= b;i--)
#define ALL(v) v.begin(),v.end()
#define PRECISION(x) cout<<fixed<<setprecision(x)
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)
#define MOD 1000000007
#define FILL fill(begin(v), end(v), x)

void solve(int n, int x, int t);
int main()
{
#ifdef OJ
	READ;
	WRITE;
#endif

	FASTIO;
	int n, x, t;
	cin >> n >> x >> t;
	solve(n, x, t);
	return 0;
}
void solve(int n, int x, int t)
{
	(n % x == 0) ? cout << t*(n / x) : cout << t*(n / x + 1);
	cout << "\n";
}