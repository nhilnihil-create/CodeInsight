#include <iostream>
using namespace std;

string s;
int a[222222], b[222222];

int main(void)
{
	int n, k, c, i;

	cin >> n >> k >> c >> s;
	s = '.' + s;

	int cnta = 0;
	a[0] = -1e8;
	for (i = 1; i <= n; i++)
		if (s[i] == 'o')
			if (i - a[cnta] > c)
				a[++cnta] = i;

	int cntb = 0;
	b[0] = 1e8;
	for (i = n; i >= 1; i--)
		if (s[i] == 'o')
			if (b[cntb] - i > c)
				b[++cntb] = i;

	for (i = 1; i <= min(cnta, k); i++)
		if (a[i] == b[min(cntb, k) - i + 1])
			cout << a[i] << "\n";
	return 0;
}