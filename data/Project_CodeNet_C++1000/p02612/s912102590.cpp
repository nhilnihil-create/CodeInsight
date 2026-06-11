#include <bits/stdc++.h>

#define I_AM_SPEED ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
using namespace std;
using ll = long long;

int32_t main() {
	int n;
	cin >> n;
	int ans = n % 1000;
	if(ans != 0){
		cout << 1000 - ans << endl;
	}
	else cout << 0 << endl;
}