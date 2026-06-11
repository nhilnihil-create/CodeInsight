#include <bits/stdc++.h>

using namespace std;

#define ll long long
#define fix cout << fixed; cout << setprecision(0)





void solve() {

	set<int> bag;
	int n = 3;
	while(n--) {
		int x;
		cin >> x;
		bag.insert(x);
	}
	if(bag.size() == 2) {
		cout << "Yes\n";
	}
	else {
		cout << "No\n";
	}
	




	
}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(NULL);
	fix;
	solve();

	return 0;
}