#include <iostream>
using namespace std;
int main()
{
	int n, m = 0;
	cin >> n;
	int arr[100];
	for (int j = 0; j < n; j++) {
		cin >> arr[j];
	}

	for (int i = 0; i < n; i+=2) {
		if (arr[i] % 2 != 0)
			m++;
	}
	cout << m;
}