#include<iostream>
using namespace std;
int main() {
	int h, w, n;
	cin >> h;
	cin >> w;
	cin >> n;

	int max;
	if (h > w) {
		max = h;
	}
	else { max = w; }
	if (n % max == 0) {
		cout << n / max << endl;
	}
	else {
		cout << (n - (n % max)) / max + 1 << endl;
	}
	return 0;

}