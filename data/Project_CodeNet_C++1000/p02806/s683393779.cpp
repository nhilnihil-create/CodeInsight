#include <bits/stdc++.h>
#include <math.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int) (n); i++)
#define ll long long
#define scout cout << fixed << setprecision(20)
ll INF = 9e17;
ll mod = 1e9 + 7;

int main() {
	int n; cin >> n;
	vector<pair<string,int>> a(n);
	rep(i,n) cin >> a[i].first >> a[i].second;
	string x; cin >> x;
	int ans = 0;
	bool ok = false;
	rep(i,n) {
		if(a[i].first==x) {
			ok=true; continue;
		}
		if(ok) ans += a[i].second;
	}
	cout << ans << endl;
}