#include<iostream>
#include<iomanip>
using namespace std;

int main(void){
	int a, b, d, r;
	double f;
	cin >> a >> b;
	cout << a / b << " " << a%b << " " << fixed << setprecision(10) << double(a) / double(b) << endl;
    return 0;
}