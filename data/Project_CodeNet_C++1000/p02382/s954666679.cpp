#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>
#include <string.h>
#include <math.h>
#define pi 3.1415926535

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> x(n), y(n);
	for(int i = 0; i < n; i++){
		cin >> x.at(i);
	}
	for(int i = 0; i < n; i++){
		cin >> y.at(i);
	}
	
	/*pow(数字, 1 / n条痕のn)*/
	double p1 = 0;
	double p2 = 0;
	double p3 = 0;
	double p4 = 0;
	int tmp_p1 = 0;
	double tmp_p2 = 0;
	double tmp_p3 = 0;
	for(int i = 0; i < n; i++){
		tmp_p1 = abs(x.at(i) - y.at(i));
		tmp_p2 += tmp_p1*tmp_p1;
		tmp_p3 += tmp_p1*tmp_p1*tmp_p1;
		p4 = max(p4, (double)tmp_p1);
		p1 += tmp_p1;
	}
	p2 = sqrt(tmp_p2);
	p3 = pow(tmp_p3, 1.0/3.0);
	
	
	printf("%.8lf\n%.8lf\n%.8lf\n%.8lf\n", p1, p2, p3, p4);
}

