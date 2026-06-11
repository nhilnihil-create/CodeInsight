#include <iostream>
#include<algorithm>
#include<string>
#include<math.h>
#include<vector>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;

int main() {
	int N;
	cin >> N;
	vector<int> data(N);
	rep(i, N) cin >> data.at(i);
	int result = 10000000000;

	for (int i = 1; i < 101; i++) {
		int sum = 0;
		rep(j, N) {
			sum += (data.at(j) - i) * (data.at(j) - i);
		}
		result = min(result, sum);
	}
	cout << result << endl;
}