#include <iostream>
#include <cmath>
using namespace std;

int main() {
	// your code goes here
	int n, x, t; cin >> n >> x >> t;
	int res = ceil(static_cast<double>(n) / static_cast<double>(x)) * t;
	
	cout << res << endl;
}
