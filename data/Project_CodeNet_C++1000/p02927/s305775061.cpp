#include<iostream>
using namespace std;

int main() {
	
	int M, D;
	cin >> M >> D;

	int count = 0;

	int d10, d1;
	for (int i = 22; i <= D; i++) {
		// d1が0or1の時スキップ
		if (i % 10 < 2) continue;
		d10 = i / 10;
		d1  = i % 10;
		if (d10 * d1 <= M) count++;
	}

	cout << count;

}