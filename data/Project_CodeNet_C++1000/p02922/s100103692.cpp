#include <iostream>
#include <string>
#include <vector>
#include <math.h>
#include <algorithm>
using namespace std;
int main() {
	int a, b,holl ;
	int ans;
	holl = 1;
	cin >> a >> b;
	for (int i = 0; i < 30; i++) {
		if (holl >= b) { ans = i; break; }
		holl += a-1;
		
	}
	cout << ans << endl;

}
