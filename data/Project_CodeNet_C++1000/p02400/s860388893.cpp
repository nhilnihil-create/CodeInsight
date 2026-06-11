#include <iostream>
#include <iomanip>
using namespace std;

int main(){
	double r,l,menseki;
	double PI= 3.141592653589;
	cin >> r;
	menseki = (double)r * r * PI;
	l = (double)2 * PI * r;
	cout << fixed << setprecision(6);
	cout << menseki << " "<< l <<endl; 



}