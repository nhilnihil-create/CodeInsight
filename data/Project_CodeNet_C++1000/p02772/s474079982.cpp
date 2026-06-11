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
	bool flag = true;
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		if(x % 2 == 0 && (x % 3 != 0 && x% 5 != 0)) flag = false;
		}
		if(flag) cout << "APPROVED" << endl;
		else cout << "DENIED" << endl;
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
 
 
 
