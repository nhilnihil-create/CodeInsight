#include <iostream>
//#include <stdio.h>
using namespace std;

int main(){
	int n;
	long long a;
	long long max=100000, min=-1000000,sum = 0;
	
	cin >> n;
	for (int i=0;i < n;i++){
		cin >> a;
		sum += a;
		if (i == 0) {max = a; min = a;} 
		if (max <= a) max = a;
		if (min >= a) min = a;
		}
	cout << min << " " << max << " " << sum << endl;
	return 0;
}