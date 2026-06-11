#include<bits/stdc++.h>							
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;


ll ans = maxn;
ll d(ll n) {
	for(ll i = sqrt(n); i >= 1; --i) {
		if(n % i == 0) {
			ans  = n / i + i;
			ans -= 2; 
			return ans;
			}
		}
}

void solve() {
	ll n;
	cin >> n;
	cout << d(n) << endl;
}


int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}
 
 
 

