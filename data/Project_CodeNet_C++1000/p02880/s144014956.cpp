#include<bits/stdc++.h>							
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;

bool d(ll n) {
	for(int i = 1; i <= sqrt(n); ++i) {
		if(n % i == 0) {
			if(n / i <= 9 && i <= 9) return true;
			}
		}
		return false;
}

void solve() {
	int n;
	cin >> n;
	if(d(n)) cout << "Yes" << endl;
	else cout << "No" << endl;
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
 
 
 

