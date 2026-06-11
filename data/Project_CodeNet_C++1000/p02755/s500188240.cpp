#include<bits/stdc++.h>			
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;

 
void solve() {			
	ll a, b, ans;
	cin >> a >> b;
	for(int 	i = 1; i <= 1000; ++i) {
		if((ll)(i * 0.08) == a && (ll)(i * 0.1) == b) {
			cout << i << endl;	
			return;
			}
		}
		cout << -1 << endl;
}


	

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}




