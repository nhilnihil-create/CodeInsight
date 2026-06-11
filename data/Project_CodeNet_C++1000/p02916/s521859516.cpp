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
	int a[n], b[n], c[n - 1];
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) cin >> b[i];
	for(int j = 0; j < n - 1; ++j) cin >> c[j];
	ll sum  = 0;
	for(int i = 0; i < n; ++i) {
		int x = a[i];
		x--;
		sum += b[x];
		if(i) {
			if(a[i] == a[i - 1] + 1) sum += c[a[i - 1] - 1];
			}
		}
		cout << sum << endl;
}


int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}
 
 
 
