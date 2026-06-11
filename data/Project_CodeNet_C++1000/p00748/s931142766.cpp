#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e7+1;
const long long MOD = 1000000007;
const long double PI = 3.1415926;
#define FOR(i,r,n) for(ll i = (ll)(r); i < (ll)(n); i++)
#define RFOR(i,r,n) for(ll i=(ll)(n-1);i>=r;i--)
#define REP(i,n) FOR(i,0,n)
#define RREP(i,n) RFOR(i,0,n)
#define ALL(x) x.begin(),x.end()
#define RALL(x) x.rbegin(),x.rend()
typedef long long int ll;
typedef vector<ll> vi;
typedef vector < pair<ll, ll > > vp;
typedef vector <string> vs;
typedef vector <char> vc;
typedef list <ll> lst;

ll n, k, ans = 0, sum = 0, cnt = 0;
string s;
char c;

/*--------------------template--------------------*/


ll dp[1000005];
ll dpOdd[1000005];

int main()
{
	REP(i, 1000001)
	{
		dp[i] = dpOdd[i] = i;
	}

	for (ll n = 2;; n++) {
		ll bNumber = n * (n + 1) * (n + 2) / 6;
		if (bNumber > 1000001) break;

		for (ll i = 0; i <= 1000001; i++) {
			if (i - bNumber < 0) continue;
			dp[i] = min(dp[i], dp[i - bNumber] + 1);
			if (bNumber % 2 == 1) dpOdd[i] = min(dpOdd[i], dpOdd[i - bNumber] + 1);
		}
	}

	for (;;) {
		ll Value;
		cin >> Value;
		if (!Value) break;
		cout << dp[Value] << " " << dpOdd[Value] << endl;
	}

	return 0;
}