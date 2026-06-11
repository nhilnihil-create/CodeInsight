#include <stdio.h>
#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <string>
#include <numeric>

using namespace std;

int n, i;

int ju(int in){
	if (in == 0)return 0;
	if (in % 10 == 3) {
		cout << " " << i;
		return 0;
	}
	ju(in / 10);
}

int main() {
	cin >> n;
	if (n > 2) cout << " " << "3";
	if (n > 5) cout << " " << "6";
	if (n > 8) cout << " " << "9";
	if (n < 10) { cout << endl; return 0; }
	for (i = 10; i <= n; i++){
		if (i % 3 == 0) cout << " " << i;
		else ju(i);
	}
	cout << endl;
}