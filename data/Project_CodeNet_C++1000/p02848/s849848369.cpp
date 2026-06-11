#include<bits/stdc++.h>							
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;


void solve() {
	int n;
	string s;
	cin >> n >> s;
	for(int i = 0; i < s.length(); ++i) {
		if((int)s[i] + n > (int) 'Z') s[i] = char(s[i] + n - (int)'Z' + (int)'A' - 1);
		else 
		s[i] = (char)((int)s[i] + n);
		}
		cout << s << endl;
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
 
 
 
