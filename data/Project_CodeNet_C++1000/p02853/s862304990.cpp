#include <iostream>
#include <cstdio>
using namespace std;

int x, y, ans;
int main() {
	cin >> x >> y;
	ans = max(0, 4-x) + max(0, 4-y);
	if(x+y==2) ans += 4;
	cout << ans*100000;
	return 0;
}