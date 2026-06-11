#include <iostream>
#include <cmath>
#include<iomanip>
#include<algorithm>
using namespace std;

int x[101], y[101];
int n;

double mink(int p){
	if (p == 0){
		double Max = 0;
		for (int i = 0; i < n; i++){
			Max = max(Max, double(abs(x[i] - y[i])));
		}
		return Max;
	}
	else{
		double sum = 0;
		for (int i = 0; i < n; i++){
			sum += pow((abs(x[i] - y[i])), p);
		}
		return pow(sum, 1.0 / (double)p);
	}
}


int main()
{
	cin >> n;
	for (int i = 0; i < n; i++){
		cin >> x[i];
	}
	for (int i = 0; i < n; i++){
		cin >> y[i];
	}
	cout << fixed << setprecision(8);
	cout << mink(1) << endl;
	cout << mink(2) << endl;
	cout << mink(3) << endl;
	cout << mink(0) << endl;

	return 0;
}