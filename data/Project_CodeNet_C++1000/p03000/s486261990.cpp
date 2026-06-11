#include<algorithm>
#include<iostream>
#include<iomanip>
#include<numeric>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
int main() {
	int n, x;
	cin >> n >> x;
	vector<int> l(n), sum(n + 1, 0);
	for(int i = 0; i < n; ++i) {
		cin >> l[i];
		if(i != 0)
			sum[i] += (sum[i - 1] + l[i]);
		else
			sum[i] += l[i];
		if(sum[i] > x) {
			cout << i+1 << endl;
			return 0;
		}
	}
	cout << n+1 << endl;
}