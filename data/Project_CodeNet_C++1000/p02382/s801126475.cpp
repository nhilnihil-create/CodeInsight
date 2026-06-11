#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){

	int n;
	cin >> n;

	int x[n], y[n];
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	for(int i = 0; i < n; i++){
		cin >> y[i];
	}

	double p[4];

	for(int i = 0; i < 3; i++){
		long temp = 0;
		for(int j = 0 ;j < n; j++){
			if(x[j] - y[j] > 0){
				temp += pow(x[j] - y[j], i + 1);
			}else{
				temp += pow(y[j] - x[j], i + 1);
			}
//			cout << temp << endl;
		}
		p[i] = pow(temp, 1.000000000 / (i + 1));
	}

	p[3] = 0;
	for(int i = 0; i < n; i++){
		int temp = 0;
		if(x[i] - y[i] > 0){
			temp = x[i] - y[i];
		}else{
			temp = y[i] - x[i];
		}
		if(temp > p[3]) p[3] = temp;
	}

	for(int i = 0; i < 4; i++){
		cout << fixed << p[i] << endl;
	}

	return 0;
}