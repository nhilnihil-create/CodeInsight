#include <iostream>
#include <math.h>
using namespace std;
int main(void)
{
	int R, t, n, max = 0, min = 0, mint = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t;
		if (i == 0) { min = t; }
		if (i == 1){
			R = t - min;
		}
		if(i > 1 && R < t - min) {
			R = t - min;
		}
		if (min > t) {
			min = t;
		}
		
	}
	cout << R << endl;
}