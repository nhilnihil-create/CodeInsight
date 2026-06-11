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
	int arr[n]; 
	for(int i = 0; i < n; ++i) {
		cin >> arr[i];
		}
		ll ans = 0; 
		for(int i = 0; i < n - 1; ++i) {
			for(int j = i + 1; j < n; ++j) {
				ans += (arr[i] * arr[j]);
				}
			}
			cout << ans << endl;
}


int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}
 
 
 

