#include <iostream>
#include<algorithm>
#include <bits/stdc++.h>
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<int> x(N);
	for (int i = 0; i < N; i++) {
		cin >> x.at(i);
	}
	int a = 100100100;
	for (int p = 0; p < 100; p++) {
		int hp = 0;
		for (int i = 0; i < N; i++) {
			hp += (x.at(i) - p) * (x.at(i) - p);
		}
		a = min(hp, a);
	}
	cout << a << endl;
}