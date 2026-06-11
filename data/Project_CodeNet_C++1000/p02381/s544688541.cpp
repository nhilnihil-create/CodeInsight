#include <iomanip>
#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n;
	double a=0 , m=0;
	while(cin>>n && n!=0){
	int *s =new int[n];
	for(int i=0;i<n;i++){
		cin>>s[i];
		m+=s[i];
	}
	m/=n;
	for(int i=0; i<n ; i++){
		a+=((s[i]-m)*(s[i]-m))/n;
	}
	cout << fixed << setprecision(9) << sqrt(a) << endl;
	delete [] s;
	a=m=0;
	}
	return 0;
}