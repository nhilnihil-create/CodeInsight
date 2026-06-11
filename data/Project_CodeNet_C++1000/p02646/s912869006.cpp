#include<iostream> 
#include <algorithm>
#include <vector>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;
#define rep(i, n) for (long long int i = 0; i < (long long int)(n); i++)
#define rep2(i, s, n) for (long long int i = (s); i < (long long int)(n); i++)

int main() {

	long long int a, v, b, w, i = 0, j = 0, t;
	cin >> a >> v >> b >> w >> t;
	
	rep(i, t+1) {
		if (a < b) {
			if (a + v * i >= b + w * i) {

				cout << "YES" << endl;
				return 0;
			}
		}
		else {
			if (a - v * i <= b - w * i) {

				cout << "YES" << endl;
				return 0;
			}
		}
	}
	cout << "NO" << endl;
	return 0;
}
