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
	int N,cnt = 0;
	cin >> N;
	for (int i = 1; i < N; i++) {
		cnt += N / i - (N%i == 0 ? 1 : 0);
	}
	cout << cnt;
}