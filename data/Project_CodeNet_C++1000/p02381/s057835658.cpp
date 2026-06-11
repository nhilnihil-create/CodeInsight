#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main(){
	int n;
	while(1){
		cin >> n;
		if(n==0) break;
		int a[n];
		for(int i=0;i<n;i++) cin >> a[i];
		double m = 0;
		for(int i=0;i<n;i++) m += a[i];
		m /= n;
		double b = 0;
		for(int i=0;i<n;i++) b += (a[i]-m)*(a[i]-m)/n;
		cout << setprecision(10);
		cout << sqrt(b) << endl;
	}
}