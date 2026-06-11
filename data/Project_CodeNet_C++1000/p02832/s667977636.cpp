#include <bits/stdc++.h>

using namespace std;

int main(void)
{
	int n;
	cin >> n;
	int a[n];
	int idx = 1;
	int last_i = -1;
	int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] == idx) {
			count += (i-last_i-1);
			last_i = i;
			idx++;
			continue;
		}
		if (i == n-1) {
			if (idx == 1) {
				cout << "-1" << endl;
				return 0;
			}
			count += i-last_i;
		}
	}
	cout << count << endl;
	return 0;
}