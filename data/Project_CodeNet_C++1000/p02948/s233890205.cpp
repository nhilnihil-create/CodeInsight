#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <sstream>
#include <algorithm>
#include <cmath>
#include <map>
#include <set>
#include <numeric>
#include <iterator>
#include <regex>
#include <queue>

using namespace std;

namespace {

}

int main()
{
	int N, M;
	cin >> N >> M;

	vector<vector<long long>> pay(M);

	for (int i = 0; i < N; ++i) {
		int curDay, curPay;
		cin >> curDay >> curPay;
		if (curDay <= M) {
			pay[curDay - 1].push_back(curPay);
		}
	}

	priority_queue<long long> que;
	long long sum(0);
	for (int i = 0; i < M; ++i) {
		// cout << "i = " << i << endl;
		vector<long long>& curPay(pay[i]);
		for (int j = 0; j < curPay.size(); ++j) {
			que.push(curPay[j]);
		}
		// cout << "i = " << i << endl;
		if (que.size() > 0) {
			sum += que.top();
			que.pop();
		}
	}

	cout << sum << endl;

	return 0;
}