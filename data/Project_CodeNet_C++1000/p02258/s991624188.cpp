#include <iostream>
#define N 200000

using namespace std;


int main() {
	int n;
	bool inf = true;
	long r[N], max;
	long sup[N];

	cin >> n;
	for(int i = 0; i < n; ++i) {
		cin >> r[i];
	}

	sup[n-2] = r[n-1];
	for(int i = n-3; i >= 0; --i) {
		if(r[i+1] > sup[i+1]) {
			sup[i] = r[i+1];
		} else {
			sup[i] = sup[i+1];
		}
	}

	for(int i = 0; i < n-1; ++i) {
		if(inf) {
			inf = false;
			max = sup[i] - r[i];
			continue;
		}

		if(sup[i] - r[i] > max) {
			max = sup[i] - r[i];
		}
	}

	cout << max << endl;

	return 0;
}