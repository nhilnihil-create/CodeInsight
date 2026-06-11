#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

int main(){
	long n = 0;
	while (cin >> n){
		if (n == 0) break;
		vector<long> s(n, 0);
		for (long i = 0; i < n; i++){
			cin >> s[i];
		}
		long t = 0;
		for (long i = 0; i < n; i++){
			t += s[i];
		}
		double ave = 0;
		ave = (double)t / n;
		double sum = 0;
		for (long i = 0; i < n; i++){
			sum += (s[i] - ave) * (s[i] - ave);
		}
		cout << fixed << sqrt(sum / n) << endl;
	}
	return 0;
}