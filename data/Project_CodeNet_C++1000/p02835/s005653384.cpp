#include <iostream>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	int sum = a + b + c;
	if (sum >= 22) {
		cout << "bust";
		return 0;
	}
	else {
		cout << "win";
		return 0;
	}

}
