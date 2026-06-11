#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;


int main() {
	int n, d; cin >> n >> d;
	vector<vector<int>>x(n,vector<int>(d));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < d; j++) {
			cin >> x[i][j];
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			double tmp = 0;
			for (int k = 0; k < d; k++) {
				tmp += (x[i][k] - x[j][k]) * (x[i][k] - x[j][k]);
			}
			double sqtmp = sqrt(tmp);
			int interger = sqtmp;
			if (sqtmp - interger == 0)ans++;			
		}
	}
	cout << ans << endl;

	return 0;
}