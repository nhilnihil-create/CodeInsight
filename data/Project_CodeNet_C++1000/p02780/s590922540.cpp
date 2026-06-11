#include <iostream>

using namespace std;

int n, k, p;

int main() {
	cin >> n >> k;
  	int P[n];
  	long long sum = 0;
  	for (int i = 0;  i < n; i++) {
    	cin >> p;
      	P[i] = p;
      	if (i < k) sum += p;
    }
  	//cout << sum << endl;
  	int l = 0;
  	int r = k;
  	long long maxSum = sum;
  	for (int i = 0; i < n-k; i++) {
    	sum = sum-P[i]+P[i+k];
      	if (sum > maxSum) {
        	maxSum = sum;
          	l = i+1;
          	r = i+k+1;
        }
    }
  	// cout << maxSum << " " << l << " " << r << endl;
  	long double ans = 0;
  	for (int i = l; i < r; i++) {
    	if (P[i] % 2 == 1) {
    		ans += P[i] / 2 + 1;
    	} else {
        	ans += P[i] / 2 + 0.5;
        }
    }
	printf("%.9Lf", ans);
	return 0;
}


