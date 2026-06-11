#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main() {
	int n;
	int x[1000],y[1000];
	double p1, p2, p3, pp;
	cin >> n;
 
	for(int i = 0; i < n; i++){
		cin >> x[i];
	}
	for(int i = 0; i < n; i++){
		cin >> y[i];
	}
 
	//p=1?????¨???
	p1 = 0.0;
	for(int j = 0; j < n; j++){
		p1 += fabs(x[j]-y[j]);
	}
	cout << setprecision(10) << p1 << " ";
 
	//p=2?????¨???
	p2 = 0.0;
	for(int j = 0; j < n; j++){
		p2 += pow(fabs(x[j]-y[j]),2.0);
	}
	cout << setprecision(10) << sqrt(p2) << " ";
 
	//p=3?????¨???
	p3 = 0.0;
	for(int j = 0; j < n; j++){
		p3 += pow(fabs(x[j]-y[j]),3.0);
	}
	cout << setprecision(10) << pow(p3,1.0/3) << " ";
 
	//p=???????????¨???
	pp = 0.0;
	double marg,max;
	max = 0.0;
	for(int j = 0; j < n; j++){
		marg = fabs(x[j]-y[j]);
		if(max <= marg)max = marg;
	}
	cout << setprecision(10) << max << endl;
 
	return 0;
}