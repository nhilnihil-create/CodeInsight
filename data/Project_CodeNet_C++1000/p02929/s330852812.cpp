#include <iostream>
#include <iomanip>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <vector>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <deque>
#define debug(x)  cerr << #x << " = " << x << endl
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair <ll, ll> pll;
typedef pair <int, int> pii;

const int maxN = 2e5 + 5;
const ll INF = 1e18;
const ll MOD = 1e9 + 7;

ll gcd(ll a, ll b) {return !b ? a : gcd(b, a % b);}
ll sq(ll x) {return (x * x) % MOD;}
ll modP(ll a, ll b) {return (!b ? 1 : (sq(modP(a, b / 2)) * (b % 2 ? a : 1)) % MOD);}

ll ans = 1;
int a[maxN];

int main(){
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n; cin >> n;
	ll f = 1;
	for (int i = 2; i <= n; i++) f = (f * i) % MOD;
	string s; cin >> s;
	if (s[0] == 'W' || s[2 * n - 1] == 'W') return cout << "0\n" << flush, 0;
	a[0] = 0;
	for (int i = 1; i < 2 * n; i++){
		if (s[i] == s[i - 1]) a[i] = 1 - a[i - 1];
		else a[i] = a[i - 1];
	}
	int l = 0, r = 0;
	for (int i = 1; i < 2 * n; i++){
		if (a[i - 1] == 0) l++;
		else r++;
		if (a[i] == 1) ans = (ans * (l - r)) % MOD;
	}
	cout << (abs(r - l) == 1 ? (ans * f) % MOD : 0) << endl;
	return 0;
}

