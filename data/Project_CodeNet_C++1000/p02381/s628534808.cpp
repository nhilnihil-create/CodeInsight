#include <iostream>
#include <cmath>
#include<iomanip>
using namespace std;

int main()
{
	int n;
	while (cin >> n, n){
		int sum = 0;
		int s[1001] = { 0 };
		for (int i = 0; i < n; i++){
			cin >> s[i];
			sum += s[i];
		}
		double ave = (double)sum / (double)n;
		double b = 0;
		for (int i = 0; i < n; i++){
			b += (s[i] - ave) * (s[i] - ave);
		}
		cout << fixed << setprecision(8);
		cout << sqrt(b / n) << endl;
	}
	return 0;
}