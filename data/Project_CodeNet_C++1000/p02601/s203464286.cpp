#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main() {
	int a,b,c,k;
	cin >> a >> b >> c >> k;
	if (b <= a) {
		while (b <= a) {
			b<<=1;
			k--;
		}
		if (k < 0) {
			cout << "No";
			return 0;
		}
	}
	
	if (c <= b) {
		while (c<=b) {
			c<<=1;
			k--;
		}
		if (k<0) {
			cout << "No";
			return 0;
		}
	}
	cout << "Yes";
	
	
	return 0;
}
