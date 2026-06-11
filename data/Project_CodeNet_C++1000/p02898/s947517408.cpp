#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_roller_coaster(void) {
	int n, k;

	cin >> n >> k;

	vector<int> h(n);

	for (int i = 0; i < n; i++)cin >> h[i];

	int ans = 0;

	for (int i = 0; i < n; i++) {
		if (h[i] >= k) ans++;
	}

	cout << ans << endl;
}

int main()
{
    b_roller_coaster();

    return 0;
}