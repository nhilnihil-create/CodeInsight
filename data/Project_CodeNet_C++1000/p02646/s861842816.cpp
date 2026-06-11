#include<iostream>
#include<vector>
#include<string>
#include<math.h>
#include<algorithm>
#include<cmath>
#include<iomanip>
#define rep(i,n) for(int i=0; i<(n); i++)
using namespace std;
typedef long long ll;
int main() {
	ll A, V;
	cin >> A >> V;
	ll B, W;
	cin >> B >> W;
	ll T;
	cin >> T;
	if (V <= W) {
		cout << "NO" << endl;
	}
	else {
		ll D = abs(A - B);
		if (D <= T*(V - W)) {
			cout << "YES" << endl;
		}
		else {
			cout << "NO" << endl;
		}
	}
	return 0;
}

