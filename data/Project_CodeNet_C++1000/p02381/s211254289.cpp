#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n; 
	while (cin >> n) {
                if(!n)return 0;
		double sum = 0;
		int a[1010];
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			sum += a[i];
		}
		sum /= n;
		double cnt = 0;
		for (int i = 0; i < n; i++) {
			cnt += pow(a[i] - sum, 2);
		}
		cnt /= n;
		printf("%.100f\n", sqrt(cnt));
	}
}