#include <iostream>
#include <vector>
#include <iomanip>
#include <cmath>
using namespace std;


int main(){
	int n;
	cin >> n;
	vector <double> x(n);
	vector <double> y(n);
	for(int i=0;i<n;i++) cin >> x[i];
	for(int i=0;i<n;i++) cin >> y[i];
	double one=0, two=0, three=0, inf=0;
	for(int i=0;i<n;i++){
		one += abs(x[i]-y[i]);
		two += pow((x[i]-y[i]), 2);
		three += pow(abs(x[i]-y[i]), 3);
		if(abs(x[i]-y[i])>inf) inf = abs(x[i]-y[i]);
	}
	two = sqrt(two); three = pow(three, 1.0/3);
	cout << fixed << setprecision(12) << one << endl << two << endl << three << endl << inf << endl;
	return 0;
}