#include<iostream>
#include<cmath>
using namespace std;
int main() {
	double a, b;
	cin >> a >> b;
	int ans;
	ans = ceil((b - 1) / (a - 1));
	cout << ans << endl;
	return 0;
}