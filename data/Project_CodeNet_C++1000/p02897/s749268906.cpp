#include<bits/stdc++.h>
#define rep(i,n) for (long long i = 0; i < (n); ++i)
//g++ -std=c++11 

using namespace std;

int main(){
	long long N;
	cin >> N;
	double odd;
	double even;
	if(N%2 == 0) {
		odd = N/2;
		even = N/2;
	} else {
		odd = N/2 + 1;
		even = N/2;
	}

	printf("%.10f\n", odd / (odd + even));
}