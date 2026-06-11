#include <bits/stdc++.h>
using namespace std;
int main(void)
{
	const long long p = (long long)1e9+7;
	string s;
	cin >> s;
	long long d[s.size()][13];
	if (s[0] == '?') {
		for (int i = 0; i < 10; i++)
			d[0][i] = 1;
		for (int i = 10; i < 13; i++)
			d[0][i] = 0;
	} else {
		for (int i = 0; i < 13; i++)
			d[0][i] = 0;
		d[0][s[0]-'0'] = 1;
	}

	for (int i = 1; i < s.size(); i++) {
		if (s[i] == '?') {
			for (int j = 0; j < 13; j++)
				d[i][j] = 0;
			for (int j = 0; j < 13; j++) {
				for (int k = 0; k <= 9; k++) {
					int tmp = (j * 10 + k)%13;
					d[i][tmp] += d[i-1][j];
					d[i][tmp] %= p;
				}
			}
		} else {
			for (int j = 0; j < 13; j++)
				d[i][j] = 0;
			for (int j = 0; j < 13; j++) {
				long long tmp = (j*10 + s[i]-'0')%13;
				d[i][tmp] = d[i-1][j];
			}
		}
	}
	cout << d[s.size()-1][5] << endl;
	return 0;
}