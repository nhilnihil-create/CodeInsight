#include <iostream>
#include <cstring>
using namespace std;

int a[100001] = {0};
int N = 1000000007;

int main () {
	int n, m, temp;
	memset(a, -1, sizeof(a));
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {cin >> temp; a[temp] = 0;}
	if (a[1] != 0) a[1] = 1;
	if (a[2] != 0 && a[1] == 0) a[2] = 1;
	if (a[2] != 0 && a[1] != 0) a[2] = 2;
	for (int i = 3; i <= n; i++) {
		a[i] = (a[i] == 0) ? 0 : (a[i-1] % N + a[i-2] % N) % N;
	}
	cout << a[n] << endl;
	return 0;
}