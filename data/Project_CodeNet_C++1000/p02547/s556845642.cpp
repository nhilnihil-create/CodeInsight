#include <bits/stdc++.h>
#define ll long long int
using namespace std;

int main() {
	int n;
	cin >> n;
	int count = 0, ans = 0;


	for(int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		if(x == y) {
			count++;
		} else {
			count = 0;
		}
		if(count == 3) {
			ans = 1; 
		}
	}

	if(ans) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}
	return 0;
}