#include<iostream>
using namespace std;
int main() {
	long long h, w; cin >> h >> w;
	long long ans = (h * w + 1) / 2;
	if (h == 1 || w == 1) ans = 1;
	cout << ans << endl;
}