#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>

using namespace std;

void b_buffet(void) {
	int n;
	cin >> n;
	vector<int> a(n+1);
	vector<int> b(n+1);
	vector<int> c(n+1);
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) cin >> b[i];
	for (int i = 1; i < n; i++) cin >> c[i];

	int sum = 0;
	for (int i = 1; i <= n; i++) {
		sum += b[a[i]];
		if (i < n) {
			if (a[i + 1] -a[i] == 1) {
				sum += c[a[i]];
			}
		}
		//cout << sum << endl;
	}

	cout << sum << endl;
}

int main()
{
    b_buffet();

    return 0;
}
