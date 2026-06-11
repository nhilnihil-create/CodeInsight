#include<bits/stdc++.h>

using namespace std;

int items[7] = {0, 100, 101, 102, 103, 104, 105};

int main() {

	// freopen("input.txt", "r", stdin);
	// freopen("output.txt", "w", stdout);

	int x;
	cin >> x;
	int first = x / 100;
	int diff = 5 * first; 
	int hundred = first * 100;
	if (x >= hundred && x <= hundred + diff) cout << 1 << '\n';
	else cout << 0 << '\n';
	return 0;
}