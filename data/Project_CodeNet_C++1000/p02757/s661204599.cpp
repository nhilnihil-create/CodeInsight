#include <bits/stdc++.h>
 
//#define endl '\n'
#define fi first
#define se second
#define MOD(n,k) ( ( ((n) % (k)) + (k) ) % (k))
#define forn(i,n) for (int i = 0; i < n; i++)
#define forr(i,a,b) for (int i = a; i <= b; i++)
#define all(v) v.begin(), v.end()
#define pb(x) push_back(x)
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ii> vii;

int n, p;
string s;
map<int, int> mp;
ll res;

int main () {
	ios_base::sync_with_stdio(0); cin.tie(0);
	
	cin >> n >> p >> s;

	mp[0] = 1;
	reverse(all(s));

	if (p == 2 || p == 5) {
		forn (i, n)
			if ((s[i] - '0') % p == 0)
				res += n - i;
		cout << res << endl;
		return 0;
	}

	for (ll i = 0, j = 1, acu = 0; i < n; i++, (j *= 10) %= p) {
		(acu += int(s[i] - '0') * j) %= p;
		res += mp[acu];
		mp[acu]++;
	}

	cout << res << endl;

	return 0;
}