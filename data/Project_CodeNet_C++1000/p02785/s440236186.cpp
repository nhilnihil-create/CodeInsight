#include<bits/stdc++.h>							
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;



void solve() {
	ll n, k;
	cin >> n >> k;
	ll health[n], sum = 0;
	for(int i = 0; i < n; ++i) {
		cin >> health[i];
		}
		sort(health, health + n);
		for(int i = 0; i < n - k; ++i) {
			sum += health[i];
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
 
 
 
