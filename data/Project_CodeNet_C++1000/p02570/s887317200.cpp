/*
	LINES :
		* //WHAT?
*/
#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef pair<int, int> pii;
typedef vector<pii> vpii;

#define OJ
#define pb push_back
#define F first
#define S second
#define WLL(t) while(t--)
#define FOR(i,a,b) for(int i = a; i < b; i++)
#define VFOR(i,a,b) for(int i = a; i >= b; i--)
#define ALL(v) v.begin(),v.end()
#define PRECISION(x) cout<<fixed<<setprecision(x)
#define FASTIO ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define READ freopen("input.txt", "r", stdin)
#define WRITE freopen("output.txt", "w", stdout)

void solve(int d, int t, int s);
int main()
{
#ifndef OJ
	READ;
	WRITE;
#endif

	FASTIO;
	int d, t, s;
	cin >> d >> t >> s;
	solve(d, t, s);
	return 0;
}
void solve(int d, int t, int s)
{
	if (s * t >= d) {
		cout << "Yes" << "\n";
	}
	else {
		cout << "No" << "\n";
	}
}