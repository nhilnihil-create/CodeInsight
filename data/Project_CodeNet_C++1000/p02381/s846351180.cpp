#include <iostream>
#include <cstring>
#include <sstream>
#include <cctype>
#include <cmath>
#include <cstdio>
using namespace std;
#define MPI  3.14159265358979323846


int main(){
	while (true){
		int n, s[1001], sum = 0;
		double a=0,m;
		cin >> n;
		if (n == 0)break;
		for (int i = 0; i < n; i++){
			cin >> s[i];
			sum += s[i];
		}
		m = (double)sum / (double)n;
		for (int i = 0; i < n; i++){
			a += pow(s[i] - m, 2) / (double)n;
		}
		printf("%.8f\n", sqrt(a));
	}
	return 0;
}
