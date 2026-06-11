#include<iostream>
#include<vector>
#include<cmath>
#include<cstdio>
using namespace std;

int main(){
	double a, m;
	int n, i;
	vector<double> s;
	cin >> n;
	while(n != 0){
		a = m = 0;
		s.reserve(n);
		for(i=0;i<n;i++){
			cin >> s[i];
			m += s[i];
		}
		m /= n;
		for(i=0;i<n;i++){
			a += (s[i] - m) * (s[i] - m);
		}
		a /= n;
		a = sqrt(a);
		printf("%.8f\n", a);
		cin >> n;
	}
	return 0;
}