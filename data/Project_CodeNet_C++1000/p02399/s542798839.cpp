#include<iostream>
#include<iomanip>
using namespace std;

int main(){
	int a,b;
	double f;
	cin >> a >> b;
	f=1.0*a/b;
	cout << a/b << " " << a%b << " " << fixed << setprecision(10) << f << endl;
}