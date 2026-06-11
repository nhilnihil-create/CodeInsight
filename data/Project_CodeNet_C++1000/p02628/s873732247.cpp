#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void b_mix_juice(void) {
	int n, k;
	cin >> n >> k;

	vector<int>a(n);
	for (int i = 0; i < n; i++)cin >> a[i];

	sort(a.begin(), a.end());

	int sum = 0;
	for (int i = 0; i < k; i++) sum += a[i];
	cout << sum << endl;
}

int main()
{
    b_mix_juice();
    return 0;
}