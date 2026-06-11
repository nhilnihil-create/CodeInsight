#include <iostream>
using namespace std;

int main(){ 
	long long a, b, r, ans = 0;
	cin >> a >> b >> r;
	ans = a / (b + r) * b;
	long long rem = a % (b + r);
	ans += (rem <= b ? rem : b);
	cout << ans;
}
