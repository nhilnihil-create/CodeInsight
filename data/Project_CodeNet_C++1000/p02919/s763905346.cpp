#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int main() {
	//cin.tie(0)->sync_with_stdio(0);
	//cin.exceptions(cin.failbit);

	int n; cin >> n;
	vi v(n + 2), jf(n + 2, n + 1), jf2(n + 2, n + 1), jb(n + 2, 0), jb2(n + 2, 0);

	rep(i, 1, n + 1) cin >> v[i];

	// build jump array
	{
		set<int> indices;
		set<int, greater<int>> indices_dec;
		
		vector<pair<int, int>> prs;
		rep(i, 1, n + 1) prs.push_back({ v[i], i });
		sort(all(prs)); reverse(all(prs));
	
		for (auto p : prs) {
			{
				auto it = indices.upper_bound(p.second);
				if (it != indices.end()) {
					jf[p.second] = *it;
					++it;
					if (it != indices.end()) {
						jf2[p.second] = *it;
					}
				}
			}
			{
				auto it = indices_dec.upper_bound(p.second);
				if (it != indices_dec.end()) {
					jb[p.second] = *it;
					++it;
					if (it != indices_dec.end()) {
						jb2[p.second] = *it;
					}
				}
			}
			indices.insert(p.second);
			indices_dec.insert(p.second);
		}
	}

	ll ans = 0;
	rep(i, 1, n + 1) {
		//printf("Elem: %d, Index: %d, Left: %d %d %d %d, Right: %d %d %d %d\n",
		//		v[i], i,
		//		jb2[i], jb[i], i, jf[i],
		//		jb[i], i, jf[i], jf2[i]);
		ll p = 0;
		p += 1ll * (jb[i] - jb2[i]) * (jf[i] - i); //printf("Left: %lld\n", 1ll * (jb[i] - jb2[i]) * (jf[i] - i));
		p += 1ll * (i - jb[i]) * (jf2[i] - jf[i]); //printf("Right: %lld\n", 1ll * (i - jb[i]) * (jf2[i] - jf[i]));
		ans += 1ll * p * v[i];
	}
	cout << ans << endl;
}
