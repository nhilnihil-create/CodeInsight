#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#define pb push_back
#define INF 0x3f3f3f3f
#define endl '\n'
#define ll long long
#define int long long
#define f first
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
const ll LINF = 0x3f3f3f3f3f3f3f;
const int MAXN = 400005;

int32_t main() {
	int a, b, c;
	cin >> a >> b >> c;
	int dif = a-b;
	cout << (dif >= c ? 0 : c-dif) << endl;
}