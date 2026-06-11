#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
#define IOS ios_base::sync_with_stdio(false); cin.tie(0);
#define pb push_back
#define PI acos(-1)
#define EPS 1e-5
#define sz(v) ((int)(v).size())
#define all(v) v.begin(),v.end()
#define forn(i, n) for(ll i=0;i<(ll)n;i++)
#define fi first
#define se second
 

int main() {
	int n, k;
	cin >> n >> k;
	vector<int> cnt(n);
	for(int i = 0; i < k; i++) {
		int d;
		cin >> d;
		forn(j, d) {
			int x;
			cin >> x;
			cnt[x-1]++;
		}
	}
	int r = count(all(cnt), 0);
	cout << r << endl;
	return 0;
}

