#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
	int n;
	double mean, std_dev;
	double scores[1000];

	while( true ){
	 	cin >> n;
	 	if(!n) break;

	 	mean = 0.0; std_dev = 0.0;
		for(int i=0; i<n; i++) cin >> scores[i];
		for(int i=0; i<n; i++) mean += scores[i] / (double)n;
		for(int i=0; i<n; i++) std_dev += pow( scores[i] - mean, 2) / (double)n;

		cout << fixed << setprecision(8) << sqrt(std_dev) << endl;
	}

	return 0;
}