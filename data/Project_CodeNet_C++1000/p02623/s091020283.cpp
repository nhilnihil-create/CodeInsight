#include<iostream>
#include<vector>
#include<string>
#include<bitset>
#include<algorithm>
#include<map>
#include<queue>
#define rep(i,n) for(int i=0;i<n;i++)

using namespace std;

int main() {
	int n, m, k;
	cin >> n >> m >> k;

	vector<int> data_a(n + 1, 0), data_b(m + 1, 0);
	vector<long long> data_a_sum(n + 1, 0), data_b_sum(m + 1, 0);
	rep(i, n) {
		cin >> data_a[i+1];
		data_a_sum[i+1] = data_a[i+1];
		if (i > 0)
			data_a_sum[i+1] += data_a_sum[i];
	}
	rep(i, m) {
		cin >> data_b[i+1];
		data_b_sum[i+1] = data_b[i+1];
		if (i > 0)
			data_b_sum[i+1] += data_b_sum[i];
	}

	int max = 0;
	int check = 0;
	for (int i = m; i > 0; i--) //机Bだけで読める最大の本
		if (data_b_sum[i] <= k) {
			check = i;
			break;
		}

	int j = 0;
	for (int i = check; i >= 0; i--) { //机Bの本を1冊づつ減らした時に読める合計本
		while (1) {
			//cout << "j=" << j << " i=" << i << endl; //確認用
			if (k < data_a_sum[j] + data_b_sum[i])
				break;
			if (i + j > max)
				max = i + j;
			if (j < n) 
				j++;
			else
				break;
		}
	}
	cout << max << endl;
	return 0;
}