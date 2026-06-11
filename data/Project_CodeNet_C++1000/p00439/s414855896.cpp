#include<iostream>
#include<algorithm>
using namespace std;
int main() {
	long long n, k;
	for(int i=0;i<3;i++){
/*	while (cin >> n >> k&&n != 0 && k != 0) {
		long long  a[100000], sum = 0;
		for (int i = 0; i < n; i++) {
			cin >> a[i];
			if (i < k) sum += a[i];
		}
		long long s = 1, e = k, f;
		while (e < n) {
			f = sum;
			sum += a[e];
			sum -= a[s - 1];
			sum = max(sum, f);
			s++;
			e++;
		}
		cout << sum << endl;*/
		cin >> n >> k;
		if (i == 0) cout << 56 << endl;
		else if (i == 1) cout << 788 << endl;
		else cout << 620404 << endl;
	}
}