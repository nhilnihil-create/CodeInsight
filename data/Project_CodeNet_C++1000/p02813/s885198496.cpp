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
	vector<int> a(n), b(n), a_c;
	for(int i = 0; i < n; ++i) cin >> a[i];
	for(int i = 0; i < n; ++i) cin >> b[i]; 
	a_c = a;
	sort(a.begin(), a.end());
	ll cnt = 0, cnt2 = 0;
	bool flag = true, flag2 = true;
	do {
		if(a == a_c) flag = false;
		if(a == b) flag2 = false;
		if(flag) cnt++;
		if(flag2) cnt2++;
		} while(next_permutation(a.begin(), a.end()));
		cout << abs(cnt - cnt2) << endl;
}


int main() {
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cout.precision(35);
	solve();
	return 0;
}
 
 
 

