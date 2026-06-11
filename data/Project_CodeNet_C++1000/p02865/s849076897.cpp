#include<iostream>
#include<stdlib.h>
#include<algorithm>
using namespace std;


int main(void) {
	int n;
	cin >> n;

	int count = 0;

	for (int i = 1; i < n; ++i) {
		int j = n - i;
		if (i != j && i > j) {
			++count;
		}
	}

	cout << count;

	return 0;
}