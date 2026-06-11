#include<bits/stdc++.h>							
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;

void solve() {
	int n;
	string s, t;
	cin >> n >> s;
	if(1 & n) {
		cout << "No" << endl;
		return;
		}
		cout << t << endl;
	for(int i = 0; i < n / 2; ++i) {
		if(s[i] != s[n / 2 + i]) {
			cout << "No" << endl;
			return;
			}
		}
		cout <<"Yes" << endl;
	}

int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}
 
 
 

