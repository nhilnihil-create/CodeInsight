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
	for(int i = 0; i < n; ++i) cin >> arr[i];
	sort(arr, arr + n);
	int l = arr[0], r = arr[n - 1];
	ll ans = maxn;
	for(int i = l; i <= r; ++i) {
		ll sum = 0;
		for(int j = 0; j < n; ++j) {
			sum += pow(abs(i - arr[j]), 2);
			}
			ans = min(ans, sum);
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
 
 
 
