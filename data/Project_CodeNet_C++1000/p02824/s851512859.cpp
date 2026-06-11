# include <bits/stdc++.h>

using namespace std;
#define _USE_MATH_DEFINES_
#define ll long long
#define ld long double
#define Accepted 0
#define pb push_back
#define mp make_pair
#define sz(x) (int)(x.size())
#define every(x) x.begin(),x.end()
#define F first
#define S second
#define lb lower_bound
#define ub upper_bound
#define For(i,x,y)  for (ll i = x; i <= y; i ++) 
#define FOr(i,x,y)  for (ll i = x; i >= y; i --)
#define SpeedForce ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0)
// ROAD to...                                                                                                                                                                                                                Red

inline void Input_Output () {
	//freopen(".in", "r", stdin);
   //freopen(".out", "w", stdout);
}

const double eps = 0.000001;
const ld pi = acos(-1);
const int maxn = 1e7 + 9;
const int mod = 1e9 + 7;
const ll MOD = 1e18 + 9;
const ll INF = 1e18 + 123;
const int inf = 2e9 + 11;
const int mxn = 1e6 + 9;
const int N = 6e5 + 123;                                          
const int M = 22;
const int pri = 997;
const int Magic = 2101;

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, -1, 0, 1};
 
int n, m, v, p;
int a[N];
ll b[N];

bool check (int x) {
	if (a[p] > a[x] + m) return 0;
	ll now = m * (ll)v;
	now -= (p-1) * (ll)m;
	for (int i = 1; i <= n; i ++) {
		if (a[i] <= a[x])
			now -= m;
	}

   	for (int i = x; i >= p; i --) {
   		if (a[x] == a[i]) continue;
   		now -= a[x] + m - a[i];
   	}
     
	return now <= 0;
}

int main () {
   	SpeedForce;
   	cin >> n >> m >> v >> p;
	for (int i = 1; i <= n; i ++) {
		cin >> a[i];
	}
	sort(a + 1, a + n + 1, greater<int>());
	int l = p, r = n + 1;
	while(l < n && a[l] == a[l+1]) l++;

	//cout << check(5);
	//exit(0);

	while (r - l > 1) {
		int md = (l + r) >> 1;
		if (check(md)) l = md;
		else r = md;
	}

	cout << l << '\n';

    return Accepted;
}

// B...a