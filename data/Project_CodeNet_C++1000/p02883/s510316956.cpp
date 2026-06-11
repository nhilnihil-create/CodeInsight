#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define INF 0x3f3f3f3
#define LINF 0x3f3f3f3f3f3f3f
#define MAXN int(2*1e5)+5
#define endl '\n'
#define ll long long
#define f first
#define s second
#define FAST cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define debug(x) cout << "DEBUG " << x << endl
#define debug2(x, y) cout << "DEBUG " << x << " " << y << endl
#define debug3(x, y, z) cout << "DEBUG " << x << " " << y << " " << z<< endl
#define debug4(x, y, z, o) cout << "DEBUG " << x << " " << y << " " << z<< " " << o << endl
#define max3(x, y, z) max(x, max(y, z))
#define ull unsigned long long

using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef pair<string, int> psi;
typedef pair<unsigned ll, pair<int, int> > piii;
typedef pair<pair<int, int>, int> piii2;
typedef tree<int,null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update> indexed_set;
const ll mod = 1e9+7;

ll n, k, p[MAXN], f[MAXN];

// qtd de treinos = diferença X-p[i]
// X = minpower to do in Y seconds;
// f/mid


bool check(ll mid) {
	ll need = 0;
	for(int i = 0; i < n; i++) {
		ll aux = p[i]*f[i];
		if(aux <= mid)
			continue;
		need += (aux-mid+f[i]-1)/f[i];
	}
	if(need <= k)
		return 1;
	else return 0;
}

ll bb() {
	ll ini = 0, mid, fim = 1e12+5, ans = LINF;
	while(ini <= fim) {
		mid = (ini+fim)/2;
		if(check(mid)) {
			ans = min(ans, mid);
			fim = mid-1;
		}
		else ini = mid+1;
	}
	return ans;
}


int32_t main() {
	FAST;
	cin >> n >> k;
	for(int i = 0; i < n; i++)
		cin >> p[i];
	for(int i = 0; i < n; i++)
		cin >> f[i];
	sort(p, p+n, greater<int>());
	sort(f, f+n);
	cout << bb() << endl;
}
