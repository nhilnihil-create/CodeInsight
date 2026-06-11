#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	double m1=0,m2=0,m3=0,mi=0;
	cin>>n;
	unsigned int *x =new unsigned int [n];
	unsigned int *y =new unsigned int [n];
	for(int i=0 ; i<n ; i++ ){
		cin >> x[i];
	}
	for(int i=0 ; i<n ; i++ ){
		cin >> y[i];
	}
	for(int i=0 ; i<n ; i++ ){
		m1+=abs((double)x[i]-(double)y[i]);
	}
	for(int i=0 ; i<n ; i++ ){
		m2+=pow(abs((double)x[i]-(double)y[i]),2.0);
	}
	m2=sqrt(m2);
	for(int i=0 ; i<n ; i++ ){
		m3+=pow(abs((double)x[i]-(double)y[i]),3.0);
	}
	m3=cbrt(m3);
	for(int i=0 ; i<n ; i++ ){
		if(mi<=abs((double)x[i]-(double)y[i])){
			mi=abs((double)x[i]-(double)y[i]);
		}
	}

	
	cout << fixed << setprecision(9) << m1 << endl;
	cout << fixed << setprecision(9) << m2 << endl;
	cout << fixed << setprecision(9) << m3 << endl;
	cout << fixed << setprecision(9) << mi << endl;
	delete [] x;
	delete [] y;
	return 0;
}