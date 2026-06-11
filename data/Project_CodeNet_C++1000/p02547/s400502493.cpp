#include <bits/stdc++.h>

using namespace std;

int main()
{
	int n;	cin >> n;

	int cnt = 0, Max = 0;
	for (int i = 0; i < n; i++) {
		int a, b;	cin >> a >> b;
		if (a == b) cnt++;
		else {
			Max = max(Max, cnt);
			cnt = 0;
		}
	}
	Max = max(Max, cnt);

	cout << (Max >= 3 ? "Yes\n" : "No\n");
	return 0;
}
