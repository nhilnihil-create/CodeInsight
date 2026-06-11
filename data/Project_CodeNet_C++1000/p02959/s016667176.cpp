#include<bits/stdc++.h>							
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;



void solve() {
	int n;
	cin >> n; 
	int a[100005], b[100005];
	ll ans = 0;
	for(int  i = 0; i < n  + 1; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) cin >> b[i];
	for(int i = 0; i < n; ++i) {
		int x = min(a[i], b[i]);
		ans += x;
		b[i] -= x;
		x = min(a[i + 1], b[i]);
		a[i + 1] -= x;
		ans += x;
		}
		cout << ans << endl;
}
	
	

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	int t;
	solve();
	return 0;
}
 
 
 
 
