#include <iostream>
using namespace std;
int main() {
	long long int h, w;
	cin >> h >> w;
	long long int ans;
	if (h == 1 || w == 1)
		ans = 1;
	else
		ans = ((w * h) + 1) / 2;
	cout << ans << "\n";
}
