#include <iostream>
#include <map>
#include <cmath>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <functional>
using namespace std;
#pragma warning (disable: 4996)

long long N, K, ans;
long long P[1 << 18];

int main() {
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> P[i];
	sort(P, P + N);
	for (int i = 0; i < K; i++) ans += P[i];
	cout << ans << endl;
	return 0;
}