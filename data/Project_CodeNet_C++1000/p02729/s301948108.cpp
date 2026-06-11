#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	int n, m, ans = 0;
	cin >> n >> m;
	ans += n * (n - 1) / 2;
	ans += m * (m - 1) / 2;
	cout << ans << endl;
	return 0;
}