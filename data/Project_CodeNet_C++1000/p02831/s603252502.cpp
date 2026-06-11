#include<bits/stdc++.h>							
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;

ll gcd(ll a, ll b) {
	if(a == 0) return b;
	return gcd(b % a, a);
}

ll lcm(ll a, ll b) {
	return a * b / gcd(a, b);
}

void solve() {
	ll a, b;
	cin >> a >> b;
	cout << lcm(a, b) << endl;
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
 
 
 

