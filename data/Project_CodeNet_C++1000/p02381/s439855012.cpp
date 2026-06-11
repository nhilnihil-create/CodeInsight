#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main () {
	int n,i;
	double sum1=0.0,sum2=0.0;
	while(cin >> n && n!=0){
		sum1=0; sum2=0;
		int b[n];
		for(i=0;i<n;i++){
			cin >> b[i];
			sum1 += b[i];
		}
		for(i=0;i<n;i++){
		sum2 += (sum1/n-b[i])*(sum1/n-b[i]);
		}
		cout << setprecision(20) << sqrt(sum2/n) << endl;
	}
}
	