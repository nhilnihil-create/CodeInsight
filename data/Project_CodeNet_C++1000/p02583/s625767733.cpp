/*
	LINES :
		* triangle making program
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

void solve(int sides[], int n);
int main()
{
#ifdef OJ
	READ;
	WRITE;
#endif

	FASTIO;
	int n{};
	cin >> n;
	int sides[n];
	FOR(i, 0, n) {
		cin >> sides[i];
	}
	solve(sides, n);
	return 0;
}
void solve(int sides[], int n)
{
	int count{};
	sort(sides, sides + n);//for minimizing if conditions sides[i]<sides[j]<sides[k]
	FOR(i, 0, n - 2) {
		FOR(j, i + 1, n - 1) {
			FOR(k, j + 1, n) {
				//cout << sides[i] << " " << sides[j] << " " << sides[k] << "\n";
				if (sides[i] != sides[j] && sides[j] != sides[k] && sides[i] + sides[j] > sides[k]) {
					count++;
				}
			}
		}
	}
	cout << count << "\n";
}