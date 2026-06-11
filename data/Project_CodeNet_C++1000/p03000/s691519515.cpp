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
	}
	for(int i = 1; i < n + 1; ++i) {
		sum[i] += sum[i - 1] + l[i - 1];
		//cout<<sum[i]<<' ';
		if(sum[i] > x) {
			cout << i << endl;
			return 0;
		}
	}
	if(sum[n] <= x)
		cout << n+1 << endl;
	else
		cout << 0 << endl;
}