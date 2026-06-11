#include "bits/stdc++.h"

using namespace std;

int main() {
	int H, N;
	cin >> H >> N;
	int Attack = 0;
	for (int n = 0;n<N;++n) {
		int num;
		cin >> num;
		Attack += num;
	}
	if (Attack >= H) {
		cout << "Yes"<< endl;
	}
	else{
		cout << "No" << endl;
	}
	return 0;
}