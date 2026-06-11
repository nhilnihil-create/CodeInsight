#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;

int main(){
	double in[1000];
	int n;
	for(;;){
		cin >> n;
		if(n==0) break;
		double s = 0, s2 = 0;

		for(int i=0; i<n; i++){
			cin >> in[i];
		}
		for(int i=0; i<n; i++){
			s += in[i];
		}
		s/=n;
		for(int i=0; i<n; i++){
			s2 += (in[i]-s)*(in[i]-s);
		}
		s2/=n;
		cout << sqrt(s2) << endl;
	}
	return 0;
}