#include <iostream>
#include <vector>
#include <limits.h>
using namespace std;
int main()
{
	int n, k, p, m;
	bool isPlus = true;
	while (cin >> n){
		if (0 == n) break;
		vector<int> A(n, 0);
		m = INT_MIN;
		p = 0;
		for (int i = 0; i < n; ++i){
			cin >> k;
			if (m < k) m = k;
			if (0 == i){
				A[p] = k;
				isPlus = (k > 0);
			}
			else {
				if (isPlus == (k > 0)){
					A[p] += k;
				}else{
					++p;
					A[p] = k;
					isPlus = !isPlus;
				}
			}
		}
		int sum = 0;
		for (int i = 0; i <= p; ++i){
			sum += A[i];
			if (sum > m) m = sum;
			if (sum < 0) sum = 0;
		}
		cout << m << "\n";
	}
	return 0;
}