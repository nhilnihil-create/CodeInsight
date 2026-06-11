#include<algorithm>
#include<iostream>
#include<iomanip>
#include<numeric>
#include<vector>
#include<cmath>
#include<set>
using namespace std;
int main() {
	int n, d;
	cin >> n >> d;
	vector<vector<int>> x(n, vector<int>(d, 0));
	for(int i = 0; i < n; ++i) {
		for(int j = 0; j < d; ++j) {
			cin >> x[i][j];
		}
	}
	int ans = 0;
	for(int i = 0; i < n - 1; ++i) {
		for(int j = i + 1; j < n; ++j) {
			long long int sum = 0;
			for(int k = 0; k < d; ++k) {
				sum += pow(x[i][k] - x[j][k], 2);
			}
			for(int k = 0; k <= 3300000; ++k) {
				if(k * k == sum)
					++ans;
			}
		}
	}
	cout << ans << endl;
}