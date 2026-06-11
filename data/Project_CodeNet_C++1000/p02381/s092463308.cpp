#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){
	while(1){
		long int sum = 0.0;
		double mean;
		double sigma2 = 0;
		int n, temp;
		cin >> n;
		if(n==0)
			break;
		int *data = new int[n]();

		for(int i=0; i<n; i++){
			cin >> temp;
			data[i] = temp;
		}

		for(int i=0; i<n; i++){
			sum += data[i];
		}
		mean = (float)sum / (float)n;

		for(int i=0; i<n; i++){
			sigma2 += pow(data[i]-mean, 2);
		}
		sigma2 /= (float)n;
		cout << fixed << setprecision(10) << sqrt(sigma2) << endl;
	}
	return 0;
}