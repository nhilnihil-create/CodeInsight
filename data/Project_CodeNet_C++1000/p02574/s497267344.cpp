#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long
#define FIO ios_base::sync_with_stdio(false);cin.tie(NULL);
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define ff first
#define ss second
#define vt vector
#define vll vt<ll>
#define pll pair<ll,ll>
#define vpll vt<pll>
#define vvll vt<vll>
#define all(v) v.begin(),v.end()
#define FOR(i,n) for(ll i=0;i<n;i++)
#define ffo(i,a,b) for(ll i=a;i<=b;i++)
#define rfo(i,a,b) for(ll i=a;i>=b;i--)
#define space cout<<"\n\n";
#define endl "\n"
#define pqmx priority_queue<ll>
#define pqmn priority_queue<ll,vll,greater<ll>>
#define fps(x,y) fixed<<setprecision(y)<<x
#define merg(a,b,c) set_union(a.begin(),a.end(),b.begin(),b.end(),inserter(c,c.begin()))
#define set_ar(arr,v) memset(arr,v,sizeof(arr))
#define go_t int testcases; cin>>testcases; ffo(caseno,1,testcases)

const ll mod = 1e9 + 7;
const ll N = 1e6 + 6;
const ll maxN = 1e6 + 5;
const ll MAX_SIZE = 2e6 + 6;
const ll INF = 0x3f3f3f3f3f3f3f3fll;
const double PI = 3.14159265359;

int dx[4] = { -1, 0, 1, 0};
int dy[4] = {0, 1, 0, -1};
// up, right, down, left

ll powerM(ll x, ll y, ll M = mod) { // default argument
	ll v = 1; x = x % M; while (y > 0) {if (y & 1)v = (v * x) % M; y = y >> 1; x = (x * x) % M;} return v;
}

ll power(ll x, ll y) {
	ll v = 1; while (y > 0) {if (y & 1)v = v * x; y = y >> 1; x = x * x;} return v;
}

ll n;
ll a[maxN];
int hash1[maxN];
int h1[maxN];

vt<int> spf(maxN);
void spfsieve() {
	for (int i = 2; i < maxN; i += 2)
		spf[i] = 2;
	for (int i = 3; i < maxN; i += 2) {
		if (spf[i] == 0) {
			spf[i] = i;
			for (int j = 2 * i; j < maxN; j += i) {
				if (spf[j] == 0)
					spf[j] = i;
			}
		}
	}
}

int main()
{
#ifndef ONLINE_JUDGE
	freopen("in6.txt", "r", stdin);
	freopen("out2.txt", "w", stdout);
#endif
	FIO
	spfsieve();
	cin >> n;
	ll g = 0;
	set<int> s[n];
	FOR(i, n) {
		cin >> a[i];
		g = __gcd(g, a[i]);
		ll t = a[i];
		while (t != 1) {
			s[i].insert(spf[t]);
			t = t / spf[t];
		}
	}
	ll f1 = 0;
	for (int i = 0; i < n; ++i) {
		for (auto& it : s[i]) {
			if (h1[it] == 1) {
				f1 = 1; break;
			}
			h1[it] = 1;
		}
	}
	if (f1 == 0)
		cout << "pairwise coprime";
	else if (g == 1)
		cout << "setwise coprime";
	else
		cout << "not coprime";
	return 0;
}
