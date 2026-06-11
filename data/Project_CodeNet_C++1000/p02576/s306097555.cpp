#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, x, t;
	cin >> n >> x >> t;
	if(n < x){
		cout << t;
		return 0;
	}
	int c = (int)((n * 1.0)/x + 0.5);
	cout << t * c;
	return 0;
};
