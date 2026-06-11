#include"bits/stdc++.h"
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)

int main() {

	float a, b;
	cin >> a >> b;

	for (int i = 13; i < 1005;i++) {
		if (0.08 * i >= a && 0.08 * i < a+1 && 0.1 * i >= b && 0.1 * i < b + 1) {
			cout << i << endl;
			return 0;
		}
	}

	
	cout << -1 << endl;
	return 0;
}