#include <iostream>
#include <math.h>
#include <iomanip>
using namespace std;

int main(){

	while(1){
		int n;
		cin >> n;

		if(n == 0) break;

		int s[n];
		double m = 0;
		for(int i = 0; i < n; i++){
			cin >> s[i];
			m += s[i];
		}
		m /= n;

		double a = 0;
		for(int i = 0; i < n; i++){
			a += pow(s[i] - m, 2);
		}
		a = sqrt(a / n);

		cout << fixed << a << endl;
	}

	return 0;
}