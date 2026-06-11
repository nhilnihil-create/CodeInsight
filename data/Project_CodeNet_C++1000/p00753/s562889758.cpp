#include <bits/stdc++.h>

using namespace std;

bool sosuu(int n) {
	for(int i = 2; i <= sqrt(n); i++) {
		if(n % i == 0) {
			return false;
		}
	}
	return true;
}

int main(void) {
	int num;
	while(1) { 
		cin >> num;
		if(num == 0) {
			break;
		}

		int sum = 0;
		for(int i = num + 1; i <= num * 2; i++) {
			if(sosuu(i)) {
				sum++;
			}
		}

		cout << sum << endl;
	}
	return 0;
}
			