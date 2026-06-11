#include <iostream>
#include <cmath>
#include <iomanip>
#include <vector>
#include <algorithm>
using namespace std;

int main(void){
	int n;
	double sum=0.0;
	cin >>n;
	vector<int> x(n);
	vector<int> y(n);
	for(int i=0; i<n; i++){
		cin >>x[i];
	}
	for(int i=0; i<n; i++){
		cin >>y[i];
	}
	for(int i=0; i<3; i++){
		sum=0.0;
		for(int j=0; j<n; j++){
			sum+=pow(abs(x[j]-y[j]), (i+1.0));
		}
		sum=pow(sum, 1.0/(i+1.0));
		cout <<fixed <<setprecision(10) <<sum <<endl;
	}
	sum=0.0;
	for(int i=0; i<n; i++){
		sum =max((int)sum, abs(x[i]-y[i]));
	}
	cout <<fixed <<setprecision(10) <<sum <<endl;
    return 0;
}