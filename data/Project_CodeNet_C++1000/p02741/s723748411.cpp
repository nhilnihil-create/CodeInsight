#include <iostream>
#include <cstdio>
using namespace std;

int n;
int a[35] = {1, 1, 1, 2, 1, 2, 1, 5, 2, 2, 1, 5, 1, 2, 1, 14, 1, 5, 1, 5, 2, 2, 1, 15, 2, 2, 5, 4, 1, 4, 1, 51};
int main() {
	cin >> n;
	cout << a[n-1];
	return 0;
}