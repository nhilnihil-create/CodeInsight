#include<bits/stdc++.h>							
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;


void solve() {
	string s;
	cin >> s;
	int n = s.length();	
	for(int i = 0; i < n; ++i) {
		if(1 & i) {
			if(s[i] == 'R') {
				cout << "No" << endl;
				return;
				}
			}
			else {
				if(s[i] == 'L') {
					cout << "No" << endl;
					return;
					}
				}	
		}
		cout << "Yes" << endl;
}	


int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}
 
 
 

