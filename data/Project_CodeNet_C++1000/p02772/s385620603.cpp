#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string>
#include <cmath>
#include<math.h>
using namespace std;

int main() {
	int n, a; cin >> n;
	bool ans = 1;
	for (int i = 0; i < n; i++){
		cin >> a;
		if (a % 2 != 1 && a % 3 != 0 && a % 5 != 0) {
			cout << "DENIED" << endl;
			return 0;
		}
	}
	cout << "APPROVED" << endl;
}