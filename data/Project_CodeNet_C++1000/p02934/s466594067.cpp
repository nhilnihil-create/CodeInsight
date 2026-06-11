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
const int MAXN = 2e5+5;

int32_t main() {
	int n;
	cin >> n;

	double ans = 0;
	for(int i = 0; i < n; i++) {
		double x;
		cin >> x;
		ans += (1.0/x);
	}
	cout <<  1.0/ans << endl;
}
