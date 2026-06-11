//#define _USE_MATH_DEFINES
#include <iostream>
//#include <stdio.h>
//#include <iomanip>
#include <vector>
//#include <string>
//#include <algorithm>
//#include <functional>
//#include <cmath>
//#include <time.h>

using namespace std;


int main(){

	int d,x,y,S;


	while (cin >> d){
		S = 0;
		x = 0;
		while (x < 600 -d){
			x += d;
			y = x*x;
			S += d * y;
		}
		cout << S << endl;
	}

	return 0;
}