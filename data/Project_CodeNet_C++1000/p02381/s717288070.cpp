#include<cstdio>
#include<iostream>
#include<cmath>
using namespace std;

int main(){
	int n;

	while (1){
		cin >> n;
		if (n == 0) break;

		double ave = 0;
		int a[n] = {};
		for (int i = 0; i < n; i++){
			cin >> a[i];
			ave += a[i];
		}
		ave /= n;

		double aa = 0;
		for (int j = 0; j < n; j++){
			aa += pow(a[j]-ave, 2);
		}

		aa /= n;

		double s = sqrt(aa);
		printf("%lf\n", s);

	}

	return 0;
}
