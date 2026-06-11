#include<iostream>
using namespace std;
int main() {
	int n, k;
	cin >> n >> k;
	int a[100001], i;
	char c;
	for (i = 0; i < n; i++) {
		cin >> c;
		if (c == 'L')
			a[i] = 1;
		if (c == 'R')
			a[i] = 0;
	}
	int p1 = 0, p2 = n - 1;
	while (a[p1] == a[p1 + 1]) 
		p1++;
	while (a[p2] == a[p2 - 1]) 
		p2--;
	if (p1 + 1 >= p2) {
		cout << n - 1 << endl;
		return 0;
	}
	int p3, p4;
	for (i = p1 + 1; i < p2; ) {
		p3 = i;
		while (a[p3] == a[0])
			p3++;
		p4 = p3 + 1;
		while (a[p4] ==a[p3])
			p4++;
		if (k > 0) {
			k--;
			for (int j = p3; j < p4; j++) {
				a[j] = (a[j] + 1) % 2;
			}
		}
		i = p4 + 1;
		if (k == 0)
			break;
	}
	int m = 0;
	for (int q = 1; q < n; q++) {
		if (a[q] == a[q - 1])m++;
		
	}
	p1 = 0, p2 = n - 1;
	while (a[p1] == a[p1 + 1])
		p1++;
	while (a[p2] == a[p2 - 1])
		p2--;
	if ((p1 + 1 == p2) && k > 0)m++;
	cout << m << endl;
	return 0;
}