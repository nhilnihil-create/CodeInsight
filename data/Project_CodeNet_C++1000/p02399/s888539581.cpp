#include <iostream>
using namespace std;

int main(){
	int a, b;
	int d, r;
	double f;

	cin >> a >> b;
	d = a / b;
	if (a >= b){
		r = a - (b * d);
	}
	else{
		r = a;
	}
	f = (double)a / b;

	cout << d << " " << r << " " << fixed << f << endl;

	return 0; 
}