#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fix cout << fixed; cout << setprecision(10)





void solve() {

	int h, n;
	cin >> h >> n;
	int sum = 0;
	while(n--) {
		int x;
		cin >> x;
		sum += x;
	}
	if(sum >= h) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	
	solve();

	return 0;
}