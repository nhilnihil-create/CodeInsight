#define _USE_MATH_DEFINES

#include <bits/stdc++.h>

#define sz(x) (int)((x).size())
#define endl '\n'
#define x first
#define y second
#define int long long
#define all(a) (a).begin(), (a).end()
#ifdef LOCAL
	#define dbg(x) cout << #x << " = " << x << endl;
#else 
	#define dbg(x)
#endif 

using namespace std;

void solve(); signed main() {
#ifdef LOCAL
    freopen("file1.txt", "r", stdin);                                       
    freopen("file2.txt", "w", stderr);
#endif
    srand(time(0));
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cout.setf(ios::fixed); cout.precision(15);
    solve();
}

const int INF = 1e18, MAXN = 1e5 + 10;

void solve() {                         
	int n;
	cin >> n;
	vector<vector<double>> pt(n, vector<double>(3));
	for (int i = 0; i < n; ++i) {
	    cin >> pt[i][1] >> pt[i][2];
	    int x = pt[i][1], y = pt[i][2];
		pt[i][0] = atan2(y, x);
	}
	sort(pt.begin(), pt.end());  
		
	vector<vector<double>> tmp = pt;
	for (int i = 0; i < sz(tmp); ++i) {
	    pt.push_back(tmp[i]);
	}	

	int ans = 0;
	for (int len = 1; len <= n; ++len) {
	    for (int i = 0; i < sz(pt) - len + 1; ++i) {
	     	int l = i, r = i + len - 1;
	     	int cx = 0, cy = 0;
	     	for (int j = l; j <= r; ++j) {
	     		cx += pt[j][1], cy += pt[j][2];
	     	}	
	     	ans = max(ans, cx * cx + cy * cy); 
	    }
	}	

	cout << sqrt((double)ans) << endl;
}	
