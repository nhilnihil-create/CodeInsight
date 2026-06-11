/*
                ******
		
        Author: Nguyen Phuc Chuong

                ******
*/

#include <bits/stdc++.h>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n;
	vector<int> d1(n), d2(n);
	for (int i = 0; i < n; i++) {
		cin >> d1[i] >> d2[i];
	}
	int tmp = 0;
	for (int i = 0; i < n; i++) {
		if (d1[i] == d2[i]) {
			tmp++;
		} else {
			tmp = 0;
		}
		if (tmp == 3) {
			cout << "Yes\n";
			exit(0);
		}
	}
	cout << "No\n";
	return 0;
}
