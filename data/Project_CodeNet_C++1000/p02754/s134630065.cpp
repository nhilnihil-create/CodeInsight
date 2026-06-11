#include<bits/stdc++.h>		
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;

 
void solve() {
	ll n, b, r,t , rem;
	cin >> n >> b >> r;	
	t = n / (r + b);
	rem = n % (r + b);	
	ll ans = t * b;
	ans += min(rem, b);		
	cout << ans << endl;
	return;
}


	

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}




