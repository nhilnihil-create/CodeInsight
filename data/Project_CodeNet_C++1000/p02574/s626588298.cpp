#include <bits/stdc++.h>
using namespace std;

#define F first
#define S second 
#define mp make_pair
#define pb push_back
#define pf push_front
#define speed_up ios_base::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define sz(x) (int)x.size()
#define szc(x) (int)strlen(x)
#define all(x) x.begin(), x.end()
#define debug cerr << "OK\n";
#define ub upper_bound
#define lb lower_bound 
#define y1 y_1
#define x1 y_2
 
typedef long long ll;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef vector<pii> vpii;
typedef set <int> si;
typedef set <ll> sll;
typedef multiset <int> msi;
typedef multiset <ll> msll;
typedef map <int, int> mi;
typedef map <ll, int> mll;
 
const int N = 1e6 + 20;
const int M = 1e6;
const int mod = 1e9 + 7;
const int inf = 2e9 + 3;
const ll INF = 1e16;

void data() {
	#ifdef PC
		freopen("main.in", "r", stdin);
		freopen("main.out", "w", stdout);
	#endif
}

/*
	BIN POISK EBANA V ROT
	DP EBANA V ROT
	DO EBANA V ROT
*/

int n, was[N];
vi p[N];

int main() {
	data();
	for (int i = 2; i <= M; ++i)
	 	if (p[i].empty())
	 		for (int j = i; j <= M; j += i)
	 			p[j].pb(i);
	cin >> n;
	int now = 0;
	for (int i = 1, x; i <= n; ++i) {
		cin >> x;
		now = __gcd(now, x);
		for (auto it : p[x])
			was[it]++;
	}
	bool f = 1;
	for (int i = 2; i <= M; ++i)
		if (was[i] > 1)
			f = 0;
	if (f)
		cout << "pairwise coprime\n";
	else if (now == 1)
		cout << "setwise coprime\n";
	else
		cout << "not coprime\n";		
}