#include "bits/stdc++.h"
using namespace std;

int main() {
	int N;
	cin >> N;
	vector<vector<int>> data(10, vector<int>(10));
	for (int n = 1;n <= N;++n) {
		int zzz = n%10;
		int tmpn = n;
		while (10 <= tmpn) {
			tmpn /= 10;
		}
		int aaa = tmpn;
		data[aaa][zzz]++; 
		//cout << aaa << "_"<<zzz<<endl;
	}
	int ans = 0;
	for (int n = 0;n < 10;++n) {
		for (int m = 0;m < 10;++m) {
			//cout << n << "_"<<m<<"_"<<data[n][m] * data[m][n]<<endl;
			ans +=  data[n][m] * data[m][n];
		}
	}
	cout << ans<<endl;
}