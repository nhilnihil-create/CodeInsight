#include<bits/stdc++.h>							
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;



void solve() {
	int n;
	map<string, ll> m;
	ll m_value = -maxn;
	cin >> n;
	for(int i = 0; i < n; ++i) {
		string s;
		cin >> s;
		m[s]++;
		m_value = max(m_value, m[s]);
		}
		for(auto x : m) if( x.second== m_value) cout << x.first << endl;
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
 
 
 
