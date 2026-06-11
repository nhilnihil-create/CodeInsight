#include <iostream>
using namespace std;

typedef long long ll;

int main () {
	ll X;
	cin >> X;
	ll ans = (X/500)*1000;
	ll tmp = X % 500;
	ans += (tmp/5)*5;
	cout << ans << endl;
	return 0;
}