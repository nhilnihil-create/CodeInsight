#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;

int a[100], b[100];

int main()
{
	int n;
	cin >> n;

	int j = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (a[i] % 2 == 0) {
			b[j] = a[i];
			j++;
		}
	}


	for (int i = 0; i < j; i++) {
		if (b[i] % 3 != 0 && b[i] % 5 != 0) {
		cout << "DENIED";
		return 0;
		}
	}

	cout << "APPROVED";
}