#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main(){
	while(true){
		int n;
		cin >> n;
		if(n == 0) break;
		int* s = new int[n];
		int sum = 0;
		for(int i = 0; i < n; i++){
			cin >> s[i];
			sum += s[i];
		}
		double m = static_cast<double>(sum) / n;
		double vn = 0;
		for(int i = 0; i < n; i++){
			vn += pow(s[i] - m, 2);
		}
		double v = vn / n;
		cout << fixed << setprecision(8) << sqrt(v) << endl;
	}
	return 0;
}