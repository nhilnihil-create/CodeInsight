#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, a, b, sum = 0, max;
	cin >> n;
	for (int i = 0; i < n; ++i) {
		cin >> a >> b;
		if (a == b) {
			sum ++;
			if (sum == 3) {
				cout << "Yes\n";
				return 0;
			}
		} else {
			sum = 0;
		}	
	}
	cout << "No\n";
	
	return 0;
}