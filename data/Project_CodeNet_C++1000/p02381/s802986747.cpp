#include <iostream>
#include <cmath>
using namespace std;

int main(){
	int n, s;
	double m, t;
	while(1){
		t = 0;
		m = 0;
		cin >> n;
		if(n == 0) break;
		for(int i = 0; i < n; i++){
			cin >> s;
			m += s;
			t += s*s;
		}
		m /= n;
		t /= n;
		printf("%.8lf\n", sqrt(t - m*m));
	}
	return 0;
}