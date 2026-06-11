#include<iostream>
using namespace std;

int a[200000], b[200000];
int max(int aa, int bb);
int main() {

	int n;
	cin >> n;
	int i;
	for (i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (i = 0; i < n; i++) {
		cin >> b[i];
	}
	long long int counter = 0;
	long long int counterA = 0, counterB = 0;

	for (i = 0; i < n; i++) {
		counterA = counterA + a[i];
		counterB = counterB + b[i];
		if (b[i] < a[i]) {
			cout << -1;
			//cout << 'a';
			return 0;
		}
	}
	int reducedflag = 0;
	int maxa;
	int k;
	int bbb;
	//cout << 111;
	while (counterB >= counterA) {
		reducedflag = 0;
		for (i = 0; i < n; i++) {
			bbb = b[i] + b[(i + 2) % n];
			if (b[(i + 1) % n] > bbb) {
				if (b[(i + 1) % n] > a[(i + 1) % n]) {
					//maxa = max(a[(i + 1) % n], max(b[i], b[(i + 2) % n]));
					k = b[(i + 1) % n] - a[(i + 1) % n];
					//cout << k;
					//cout << bbb;
					if (k >= bbb) {
						b[(i + 1) % n] = (b[(i + 1) % n] - (k - (k % bbb)));
						counter = counter + (k - (k % bbb)) / bbb;
						counterB = counterB - (k - (k % bbb));
						reducedflag = 1;
						if (counterB == counterA) {
							cout << counter;
							return 0;
						}
					}

				}
			}
		}
		if (reducedflag == 0) {
			cout << -1;
			//cout << 'i';
			return 0;
		}
	}


	//cout << 'u';
	cout << -1;
	return 0;
}
int max(int aa, int bb) {
	if (aa >= bb) {
		return aa;
	}
	else {
		return bb;
	}
}