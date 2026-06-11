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
	map<int, int> m;
	bool flag = true;
	for(int i = 0; i < n; ++i) {
		int x;
		cin >> x;
		m[x]++;
		if(m[x] > 1) flag = false;
		}
		if(flag) cout << "YES" << endl;
		else cout << "NO" << endl;
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
 
 
 
