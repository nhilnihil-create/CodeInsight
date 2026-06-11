#include <math.h>
#include <iostream>
#include <string.h>
using namespace std;

int main()
{
	int n = 0;
	//double ave = 0, sum = 0;	
	while (cin >> n,n != 0) {
		int temp[1001];
		double ave = 0, sum = 0;
		memset(temp, 0, sizeof(temp));
		int cnt = n;
		while (cnt) {
			cin >> temp[n - cnt];
			sum += temp[n - cnt];
			cnt--;
		}
		ave = sum / n;
		double db = 0;
		for (int i = 0; i < n; i++) {
			db += pow(temp[i] - ave, 2);
		}
		cout << fixed << sqrt(db / n) << endl;
	}
	return 0;
}