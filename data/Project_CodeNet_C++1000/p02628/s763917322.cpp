#include<algorithm>
#include<iostream>
#include<vector>
#include<string>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
#include<set>
#include<map>

using namespace std;
long long MOD = 1000000007LL;
const double PI = 3.14159265358979323846;
#undef INT_MIN
#undef INT_MAX
#define INT_MIN -2147483648
#define INT_MAX 2147483647
#define endl "\n"

int main() {
	int N, K;
	cin >> N >> K;
	vector<int> p(N);
	for (int i = 0; i < N; ++i) {
		cin >> p[i];
	}

	sort(p.begin(), p.end());

	int sum = 0;
	for (int i = 0; i < K; ++i) {
		sum += p[i];
	}

	cout << sum << endl;
	return 0;
}