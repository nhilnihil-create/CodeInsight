#include <bits/stdc++.h>
using namespace std;
#define sz(x) int(x.size())
#define pb push_back
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define ff first
#define ss second
typedef long long ll;
typedef pair<int, int> ii;

const int N = 1e5 + 2;
const ll Mod = 1e9 + 7;

string s;
ll dp[N][15];

ll go(int pos, int rem){
	if(pos == sz(s)) return (rem == 5);
	ll &ans = dp[pos][rem];
	if(ans != -1) return ans;
	ans = 0;
	int lf = 0, rg = 9;
	if(s[pos] != '?') {
		lf = rg = int(s[pos] - '0');
	}
	for(int d = lf; d <= rg; ++ d){
		ans += go(pos + 1, (rem*10LL + d) % 13);
		if(ans >= Mod) ans -= Mod;
	}
	return ans;
}

int main(){
	fastio;
	cin >> s;
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0) << endl;
	return 0;
}

