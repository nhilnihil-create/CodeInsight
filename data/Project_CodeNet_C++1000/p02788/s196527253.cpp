#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f
#define MAXN 2*int(1e5)+5
#define endl '\n'
#define ll long long
#define f first
#define s second
#define int long long
#define FAST cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define debug(x) cout << "DEBUG " << x << endl
#define debug2(x, y) cout << "DEBUG " << x << " " << y << endl
#define debug3(x, y, z) cout << "DEBUG " << x << " " << y << " " << z<< endl
#define debug4(x, y, z, o) cout << "DEBUG " << x << " " << y << " " << z<< " " << o << endl
using namespace std;
typedef pair<ll, ll> pii;
const ll mod = 1e9+7;
 
int32_t main(){
	int n, r, d;
	cin >> n >> r >> d;
	vector<pii> v(n);
	for(pii &i : v)
		cin >> i.f >> i.s;
	sort(v.begin(), v.end());
		
	ll last = 0;
	ll qtd = 0, ans = 0;
	set<pii> rmv;
	
	
	for(int i = 0; i < n; i++) {
		
		for(auto &x : rmv) {
			if(x.f < v[i].f) {
				qtd -= x.s;
				rmv.erase(x);
			}
			else break;
		}
		
		v[i].s -= qtd;
		if(v[i].s <= 0) continue;
		
		
		
		ll k = (v[i].s+d-1)/d;
		ans += k;
		qtd += k*d;
		last = v[i].f+2*r;
		
 
		
		rmv.insert({last, k*d});
		
	}
	
	cout << ans << endl;
 
}