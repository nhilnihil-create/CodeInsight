

#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
using namespace std;

typedef pair<int, int> pii;
typedef long long ll;



int main() {
	ll x;
	cin >> x;

	for (ll a = -1000; a <= 1000; a++) {
		for (ll b = -1000; b <= 1000; b++) {
			ll a5 = 1;
			ll b5 = 1;
			for (int i = 0; i < 5; i++) {
				a5 *= a;
				b5 *= b;
			}

			

			if (a5 - b5 == x) {
				cout << a << " " << b << endl;
				return 0;
			}

			
		}
	}

}