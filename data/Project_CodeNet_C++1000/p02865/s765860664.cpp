#include <bits/stdc++.h>

using namespace std;

int main(void) {
	int num, ans;
	cin >> num;
	ans = num / 2;
	if (num % 2 == 0)
		ans--;
	
	cout << ans << endl;

	return 0;
}
