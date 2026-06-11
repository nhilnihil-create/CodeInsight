#include <bits/stdc++.h>

#define IOS ios_base::sync_with_stdio(false); cin.tie(NULL);
#define pb push_back
#define pf push_front
#define pof pop_front
#define pob pop_back
#define ull unsigned long long
#define ll long long
#define sz(a) a.size()
#define all(s) s.begin(), s.end()
#define rall(s, n) s, s + n
#define x first
#define y second
#define mp make_pair
#define ub upper_bound
#define lb lower_bound
#define pii pair <int, int>
#define pll pair <ll, ll>
#define INF 1000000000
#define mod 1000000007
#define reset(a, nilai) memset(a, nilai, sizeof(a))
using namespace std;

string s;
int main () {
	IOS;

	cin >> s;
	if ((s[0] != s[1]) && (s[2] == s[3]) && (s[4] == s[5])) {
		cout << "Yes";
	} else {
		cout << "No";
	}
	cout << '\n';
	return 0;
}
