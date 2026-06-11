#include<bits/stdc++.h>							
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;



void solve() {
	int n, k;
	cin >> n >> k;
	ll sum = 0;
	for(int i = 0; i < k; ++i) {
		int x;
		cin >> x;  
		sum += x;
		}
		if(sum < n) cout << "No" << endl;
		else cout << 	"Yes" << endl;
}


int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}
 
 
 
