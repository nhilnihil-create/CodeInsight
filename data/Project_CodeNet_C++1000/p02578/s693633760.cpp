/*
	LINES :
		* height stool
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

// #define OJ
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

#define TO(v, type) static_cast<type>(v)

void solve(int row[], int n);
int main()
{
#ifdef OJ
	READ;
	WRITE;
#endif

	FASTIO;
	int n{};
	cin >> n;
	int row[n];
	FOR(i, 0, n) {
		cin >> row[i];
	}
	solve(row, n);
	return 0;
}
void solve(int row[], int n)
{
	int mx = row[0];
	ll count{};
	FOR(i, 0, n) {
		mx = max(row[i], mx);
		count += mx - row[i];
	}
	cout << count << "\n";
}