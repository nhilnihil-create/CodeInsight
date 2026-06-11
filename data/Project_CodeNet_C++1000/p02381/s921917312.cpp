#include <iostream>
#include <iomanip>
#include <cmath>
#include <numeric>
using namespace std;

int main(){
	int n;
	while(cin >> n && n){
		int s[n];
		for(int &i:s) cin >> i;
		double sum = accumulate(s, s + n, 0.0), ave = sum / n;
		double ans = 0;
		for(int &i:s) ans += (i - ave) * (i - ave);
		cout << fixed << setprecision(10) << sqrt(ans / n) << endl;
	}
}