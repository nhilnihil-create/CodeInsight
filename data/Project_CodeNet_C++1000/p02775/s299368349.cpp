#include <iostream>
#include <cstdio>
using namespace std;

int s, n, d[15], a[1000005];
string ta;
int main()
{
	int i, t;
	cin >> ta;
	ta = "00" + ta;
	n = ta.size();
	for (i = 0; i < n; i++) a[i] = ta[i] - '0';
	for (i = n - 1; i >= 0; i--) {
		t = a[i];
		if (t >= 10) {
			a[i] -= 10;
			a[i - 1]++;
		} else if (t >= 6) {
			s += 10 - t;
			a[i] = 0;
			a[i - 1]++;
		} else if (t == 5) {
			s += 5;
			a[i] = 0;
			if (a[i - 1] >= 5) {
				a[i - 1]++;
			}
		}
	}
	for (i = 0; i <= 5; i++) d[i] = i;
	for (i = 6; i <= 9; i++) d[i] = 11 - i;
	for (i =0; i < n; i++) {
		s += d[a[i]];
	}
	cout << s << endl;
    return 0;
}
