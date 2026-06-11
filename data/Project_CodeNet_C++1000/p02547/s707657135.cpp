#include <string>
#include <vector>
#include <string.h>
#include <iostream>
#include <stack>
#include <queue>
#include <algorithm>
#include <set>
#include <random>
using namespace std;
typedef long long ll;
const int INF = 987654321;
const int MAX_N = 3e5 + 2, MAX_X = 1e6 + 2;

int main()
{
	int N;
	cin >> N;
	vector<pair<int,int>>v(N);
	for (auto&i : v)cin >> i.first >> i.second;

	for (int i = 0; i < N - 2; i++)
	{
		bool flag = true;
		for (int j = 0; j < 3; j++)
			if (v[i + j].first != v[i + j].second)flag = false;
		if (flag) {
			cout << "Yes";
			return 0;
		}
	}
	cout << "No";
}