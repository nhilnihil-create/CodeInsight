#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;
 
int main() {
	int n,sum,sc[1000];
	double ave,S;
	while(1){
		cin >> n;
		if(n == 0)break;
		S = 0;
		sum = 0;
		for(int i = 0; i < n; i++){
			cin >> sc[i];
			sum += sc[i];
		}
		ave = 1.0*sum/n;
 
		for(int i = 0; i < n; i++){
			S += pow(sc[i]-ave,2)*1.0;
		}
		cout  << setprecision(10) << sqrt(S/n) << endl;
	}
	return 0;
}