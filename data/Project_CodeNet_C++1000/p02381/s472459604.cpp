#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n;
	while(true){
		cin >> n;
		if(n == 0) break;
		int s[n];
		int sum = 0;
		int sqsum = 0;
		for(int i = 0; i < n; ++i){
			cin >> s[i];
			sum += s[i];
			sqsum += s[i] * s[i];
		}
		double v = sqsum / (double)n - (sum / (double)n) * (sum / (double)n);
		cout << setprecision(10) << sqrt(v) << endl;
	}
	return 0;
}