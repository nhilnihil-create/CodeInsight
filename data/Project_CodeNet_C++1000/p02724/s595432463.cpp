#include <bits/stdc++.h>
using namespace std;

void solve(){
	int x;
	cin >> x;
	int fifty, three;
	fifty = x / 500;
	x %= 500;
	three = x / 5;
	cout << (long long) fifty * 1000 + (5 * three) << "\n"; 
}

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	solve();
}