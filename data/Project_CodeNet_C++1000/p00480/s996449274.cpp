#include<iostream>
using namespace std;
int main() {
	long long int num[100][21]{0};
	int n;
	cin >> n;
	int input[100];
	for (int i = 0; i < n; ++i) {
		cin >> input[i];
	}
	num[0][input[0]]=1;
	for (int i = 1; i < n - 1; ++i) {
		for (int j = 0; j <= 20; ++j) {
			if (j + input[i] <= 20) {
				num[i][j] += num[i - 1][j + input[i]];
			}
			if (j - input[i] >= 0) {
				num[i][j] += num[i - 1][j - input[i]];
			}
		}
	}
	cout << num[n - 2][input[n - 1]] << endl;
	return 0;
}