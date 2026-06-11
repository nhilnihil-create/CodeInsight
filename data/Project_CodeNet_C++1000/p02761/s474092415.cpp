#include<bits/stdc++.h>							
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;



void solve() {
	int n, m;
	cin >> n >> m;
	string s(n, '0');
	for(int i = 0	;i < m; ++i) {
		int idx, v;
		cin >> idx >> v;
		--idx;	
		if((s[idx] != '0' && s[idx] != v + '0') || (n != 1 && idx == 0 && v == 0)) {
			cout << -1 << endl;
			return; 
			}
			s[idx] = v + '0';
		}
		if(n > 1 && s[0] == '0') s[0] = 1 + '0';
		cout << s << endl;
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
 
 
 
