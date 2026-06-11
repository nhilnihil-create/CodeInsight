#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fix cout << fixed; cout << setprecision(10)





void solve() {

	int a, b;
	cin >> a >> b;
	if(a >= b) {
		for(int i = 0; i < a; i++) {
			cout << b;
		}
	}
	else {
		for(int i = 0; i < b; i++) {
			cout << a;
		}
	}
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	solve();

	return 0;
}