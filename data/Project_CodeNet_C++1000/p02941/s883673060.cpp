//#pragma GCC optimize("O3")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
#define mem(a,v) memset((a), (v), sizeof (a))
#define enl printf("\n")
#define case(t) printf("Case #%d: ", (t))
#define ni(n) scanf("%d", &(n))
#define nl(n) scanf("%lld", &(n))
#define nai(a, n) for (int i = 0; i < (n); i++) ni(a[i])
#define nal(a, n) for (int i = 0; i < (n); i++) nl(a[i])
#define pri(n) printf("%d\n", (n))
#define prl(n) printf("%lld\n", (n))
#define pii pair<int, int>
#define pil pair<int, long long>
#define pll pair<long long, long long>
#define vii vector<pii>
#define vil vector<pil>
#define vll vector<pll>
#define vi vector<int>
#define vl vector<long long>
#define pb push_back
#define mp make_pair
#define fi first
#define se second
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
typedef cc_hash_table<int,int,hash<int>> ht;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> oset;
const double pi = acos(-1);
const int MOD = 1e9 + 7;
const int INF = 1e9 + 7;
const int MAXN = 1e6 + 5;
const double eps = 1e-9;
int a[MAXN], b[MAXN];

int main() {
	int n; ni(n);
	nai(a, n);
	nai(b, n);
	priority_queue<pii> pq;
	for (int i = 0; i < n; i++)
		pq.push(mp(b[i],i));
	ll ans = 0;
	while (!pq.empty()) {
		pii cur = pq.top(); pq.pop();
		if (b[cur.se] != cur.fi || b[cur.se] == a[cur.se])
			continue;
		if (b[cur.se]-a[cur.se] < b[(cur.se+1)%n] + b[(cur.se-1+n)%n])
			return !pri(-1);
		ll val = (ll)((b[cur.se]-a[cur.se]) / (b[(cur.se+1)%n] + b[(cur.se-1+n)%n]));
		ans += val;
		b[cur.se] -= val * (ll)(b[(cur.se+1)%n] + b[(cur.se-1+n)%n]);
		cur.fi = b[cur.se];
		pq.push(cur);
		pq.push(mp(b[(cur.se-1+n)%n],(cur.se-1+n)%n));
		pq.push(mp(b[(cur.se+1)%n],(cur.se+1)%n));
	}
	prl(ans);
	return 0;
}
