/*
	LINES :
		check for the patterns size of t.size() and count (need to modify)
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

// #define OJ
#define pb push_back
#define F first
#define S second
#define WLL(t) while(t--)
#define FOR(i,a,b) for(int i = a; i < b; i++) // for string
#define STF(i, a, b) for(size_t i = a; i < b; i++)
#define RFOR(i,a,b) for(int i = a; i >= b; i--)
#define STRF(i, a, b) for(size_t i = a; i >= b; i--) // for string
#define ALL(v) v.begin(),v.end()
#define PRECISION(x) cout<<fixed<<setprecision(x)
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)

void solve(string s , string t, size_t lens, size_t lent);
int main()
{
#ifdef OJ
	READ;
	WRITE;
#endif

	FASTIO;
	string s, t;
	cin >> s >> t;
	size_t lens{s.size()};
	size_t lent{t.size()};
	solve(s, t, lens, lent);
	return 0;
}
void solve(string s , string t, size_t lens, size_t lent)
{
	//the highest possible is lent
	size_t ans{lent};
	//to go through all the patterns of each lent
	size_t siz = lens - lent;
	for (size_t i = 0; i <= siz; i++) {
		size_t tomod{0};// need to modify
		STF(j, 0, lent) {
			if (s[i + j] != t[j])
			{
				tomod++;
			}
		}
		ans = min(ans, tomod);
	}
	cout << ans << "\n";
}