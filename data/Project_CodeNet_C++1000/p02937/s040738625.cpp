#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define INF 0x3f3f3f3f
#define LINF 0x3f3f3f3f3f3f3f
#define endl '\n'
#define ll long long
#define f first
#define int long long
#define s second
#define FAST cin.tie(0), cout.tie(0), ios::sync_with_stdio(0)
#define debug(x) cout << "DEBUG " << x << endl
#define debug2(x, y) cout << "DEBUG " << x << " " << y << endl
#define debug3(x, y, z) cout << "DEBUG " << x << " " << y << " " << z<< endl
#define debug4(x, y, z, o) cout << "DEBUG " << x << " " << y << " " << z<< " " << o << endl
using namespace std;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> ppi;
typedef vector<vector<int>> mat;
const ll mod = 1e9+7;
const int MAXN = 2*1e5+10;

int32_t main() {
	string s, t;
	cin >> s >> t;
	
	ll ans = 0;
	
	set<int> fila[27];
	
	for(int i = 0; i < s.size(); i++)
		fila[s[i]-'a'].insert(i);
	
	int posi = -1;
	for(auto i : t) {
		if(fila[i-'a'].size() == 0) {
			cout << -1 << endl;
			return 0;
		}
		auto it = fila[i-'a'].upper_bound(posi);
		
		if(it == fila[i-'a'].end()) {
			ans += (s.size() - posi) + *fila[i-'a'].begin();
			posi = *fila[i-'a'].begin();
		}
		else {
			ans += *it - posi;
			posi = *it;
		}
	}
	cout << ans << endl;
	
	return 0;
}
