#include<iostream>

using namespace std;

int main(void) {

	int n[5];
	int ans = 0;

	for (int i = 1; i <= 5; i++) {

		cin >> n[i];

		if (n[i] == 0) {

			ans = i;
			break;

		}
	}

	cout << ans;


	return 0;
}