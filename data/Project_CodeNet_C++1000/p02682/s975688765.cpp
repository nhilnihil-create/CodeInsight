#include <iostream>
#include <cmath>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;

#define PI 3.14159265358
typedef long long ll; 
typedef long double ld; 

int main() {
	int a, b, c, k, ans = 0, t;
	cin >> a >> b >> c >> k;
	if(a < k) {
		t = k - a;
		ans = k - t;
		k = t;
		if(b < k) {
			t = k - b;
			k = t;
			k *= -1;
			ans += k;
		}
	} else {
		t = a - k;
		ans = a - t;
	}
	cout << ans << endl;
	
	return 0;
}
