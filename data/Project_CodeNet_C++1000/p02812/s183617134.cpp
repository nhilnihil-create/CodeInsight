#include<bits/stdc++.h>							
typedef long long ll;
#define pb push_back
#define mod 1000000007ll
const ll maxn = 9e18;
using namespace std;
const ll maxsize = 100000009;


int wa[100005];
void solve() {
	int n, cnt = 0;
	string s;
	cin >> n >> s;
	for(int i = 0; i < n - 2;) {
		if(s.substr(i, 3) == "ABC") cnt++, i += 3;
		else i++;
		}
		cout << cnt << endl;
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
 
 
 

