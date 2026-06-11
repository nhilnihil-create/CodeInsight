#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define pf push_front
#define PI acos(-1)
#define EPS 1e-5
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define forn(i, n) for(ll i=0;i<(ll)n;i++)
#define fi first
#define se second
 

int main() {
	int n;
	cin >> n;
	vector<vector<int>> cnt(10, vector<int>(10, 0));
	for(int i = 1; i <= n; i++) {
		string s = to_string(i);
		cnt[s[0]-'0'][s[sz(s)-1]-'0']++;
	}
	ll res = 0;
	forn(i, 10) forn(j, 10)
		res += cnt[i][j] * cnt[j][i];
	cout << res << endl;
	return 0;
}

