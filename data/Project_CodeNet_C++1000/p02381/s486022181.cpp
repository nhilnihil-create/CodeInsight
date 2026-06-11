#include <iomanip>
#include <iostream>
#include <cmath>

using namespace std;

int main(){
	int n;
	cout << fixed << setprecision(5);
	while(cin >> n && n){
		double input, sum = 0.0, sum2 = 0.0;
		for(int i = 0; i < n; i++){
			cin >> input;
			sum += input;
			sum2 += input*input;
		}
		double mean = sum/n;
		cout << sqrt(sum2/n - mean*mean) << endl;
	}
	return 0;
}