//#define _USE_MATH_DEFINES
#include <iostream>
#include <stdio.h>
//#include <iomanip>
#include <vector>
//#include <string>
//#include <algorithm>
//#include <functional>
#include <cmath>

using namespace std;

int main(){

	int n,buf;
	double ave, a;
	vector <int> s;



	while (1){
		cin >> n;
		if (n == 0)break;

		ave = 0;
		a = 0;
		s.clear();
		for(int i = 0; i < n; i++) {
			cin >> buf;
			s.push_back(buf);
			ave += buf;
		}
		ave /= n;

		for (int i = 0; i < n; i++){
			a += pow((s[i] - ave), 2);
		}
		a = sqrt((a / n));

		printf("%.6f\n", a);
	}


	return 0;
}