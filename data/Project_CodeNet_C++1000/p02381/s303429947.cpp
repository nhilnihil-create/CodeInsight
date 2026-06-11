#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main() {
	int n, s[1010];
	double ave, sum, alpha;
	while (1) {
		ave = 0; sum = 0; alpha = 0;
		cin >> n;
		if (n == 0) break;
		for (int i = 0; i < n; i++) {
			cin >> s[i];
			sum += s[i];
		}
		ave = sum / n;

		for (int i = 0; i < n; i++) {
			alpha += (s[i] - ave)*(s[i] - ave);
		}
		alpha /= n;
		alpha = sqrt(alpha);
		cout << fixed << setprecision(6) << alpha << endl;
	}
	return 0;
}