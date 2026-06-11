//code by lynmisakura.wish to be accepted!
/****************************/
#include<iostream>
#include<iomanip>
#include<math.h>
#include<vector>
#include<string>
#include<stack>
#include<queue>
#include<map>
#include<algorithm>
#include<bitset>
#include <climits>
#include<set>
#include<bitset>
using namespace std;
/***************************/
typedef long long ll;
typedef vector<int> vi;
typedef vector<long long> vl;
typedef pair<int, int> pi;
typedef vector<pair<int, int>> vpi;

const long long INF = 1LL << 55;

#define itn int
#define endl '\n'
#define pb push_back
#define mp make_pair
#define ss second
#define ff first
#define dup(x,y) ((x) + (y) - 1)/(y)
#define mins(x,y) x = min(x,y)
#define maxs(x,y) x = max(x,y)
#define all(x) (x).begin(),(x).end()
#define Rep(n) for(int i = 0;i < n;i++)
#define rep(i,n) for(int i = 0;i < n;i++)
#define rrep(i,n) for(int i = n - 1;i >= 0;i--)
#define UNIQUE(v) v.erase( unique(v.begin(), v.end()), v.end() )

ll gcd(ll a, ll b) { return b ? gcd(b, a%b) : a; }
ll qp(ll a, ll b) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a; a = 1ll * a*a; } while (b >>= 1); return ans; }
ll qp(ll a, ll b, int mo) { ll ans = 1; do { if (b & 1)ans = 1ll * ans*a%mo; a = 1ll * a*a%mo; } while (b >>= 1); return ans; }

#define _GLIBCXX_DEBUG
#define debug(x) cerr << #x << " = " << (x) << " (L" << __LINE__ << ")" << " " << __FILE__ << endl;

ll n;
vector<ll> a;
int main(void) {
	cin >> n;
	rep(i, n) {
		ll x; cin >> x;
		a.pb(x);
	}

	sort(all(a));
	vector<ll> p, m;
	p.pb(a[n - 1]);
	m.pb(a[0]);
	for (int i = 1; i < n - 1; i++)
	{
		if (a[i] < 0) m.pb(a[i]);
		else p.pb(a[i]);
	}

	vector<pair<ll, ll>> ans;
	int ps = p.size();
	int ms = m.size();
	for (int i = 0; i < ps - 1; i++) {
		ll x = *p.begin();
		p.erase(p.begin());
		ans.pb(mp(*m.begin(), x));
		*m.begin() -= x;
	}
	ll q = *p.begin();
	for (int i = 0; i < ms - 1; i++) {
		ll x = *m.begin();
		ans.pb(mp(q, x));
		m.erase(m.begin());
		q -= x;
	}
	cout << q - *m.begin() << endl;
	ans.pb(mp(q, *m.begin()));
	for (auto i : ans)
	{
		cout << i.first << " " << i.second << endl;
	}
	return 0;
}