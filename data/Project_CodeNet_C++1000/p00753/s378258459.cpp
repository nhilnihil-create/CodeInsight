#include<iostream>
#include<vector>
#include<string>
#define N 246913
using namespace std;

int main() {
	vector<bool>hantei(N, true);
	vector<int>sosuu(N);
	for (int a = 0; a < N; a++) {
		hantei[a] = true;
	}
	sosuu[0] = sosuu[1] = 0;
	int s = 0;
	for (int b = 2; b < N; b++) {
		if (hantei[b]) {
			s++;
			for (int c = b * 2; c < N; c += b) hantei[c] = false;
		}
		sosuu[b] = s;
	}
	int d;
	while (cin >> d, d) {
		cout << sosuu[d * 2] - sosuu[d] << endl;
	}
}