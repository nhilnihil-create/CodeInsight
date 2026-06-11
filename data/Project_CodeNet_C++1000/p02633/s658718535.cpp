#include <bits/stdc++.h>

using namespace std;

int main() {
	int k;
	cin >> k;

	int i = 1;
	while (i * k % 360) {
		i++;
	}

	cout << i;
}
