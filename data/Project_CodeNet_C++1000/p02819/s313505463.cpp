#include<bits/stdc++.h>							
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;

bool isPrime(ll n) {
	if(n == 2) return true;
	for(int i = 2; i <= sqrt(n);) {
		if(n % i == 0) return false;
		if(i == 2) i++;
		else i += 2;
		}
		return true;	
}

void solve() {
	ll x;
	cin >> x;
	while(!isPrime(x)) x++;
	cout << x << endl;
}


int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}
 
 
 

