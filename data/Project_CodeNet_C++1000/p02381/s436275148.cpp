#include <iostream>
#include <iomanip>
#include <math.h>
using namespace std;

int main(){
	int n;
	while(cin >> n){
		if(n==0)break;
		int s[n];
		long double m = 0,a = 0;
		for(int i = 0;i < n;i++){
			cin >> s[i];
			m += s[i];
		}
		m /= n;
		for(int i = 0;i < n;i++){
			a += (s[i] - m)*(s[i] - m);
		}
		a /= n;
		a = sqrtl(a);
		cout << setprecision(18) << a << "\n";
	}
	return 0;
}