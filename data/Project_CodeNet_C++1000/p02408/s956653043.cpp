#include<iostream>
#include<stdio.h>
using namespace std;
int main(void) {
	char a[52], x[52] = {};
	int y[52], n;
	cin>>n;
	for (int i = 0; i < n; i++) {
		cin>>a[i]>>y[i];
		if (a[i] == 'S') {
			x[4 * y[i]-4] = 1;
		}
		else if (a[i] == 'H') {
			x[4 * y[i] - 1] = 1;
		}
		else if (a[i] == 'C') {
			x[4 * y[i] - 2] = 1;
		}
		else  {
			x[4 * y[i] - 3] = 1;
		}
	}
	for (int i = 1; i <= 13; i++) {
		if (x[4 * i-4] == 0)
			cout << 'S' << " " << i << endl;
	}
	for (int i = 1; i <= 13; i++) {
		if (x[4 * i - 1] == 0)
			cout << 'H' << " " << i << endl;
	}
	for (int i = 1; i <= 13; i++) {
		if (x[4 * i - 2] == 0)
			cout << 'C' << " " << i << endl;
	}
	for (int i = 1; i <= 13; i++) {
		if (x[4 * i - 3] == 0)
			cout << 'D' << " " << i << endl;
	}
    return 0;
}

    
