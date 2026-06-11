#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
	int N, M;
	long long K;
	cin >> N >> M >> K;
	vector<long long> A(N), B(M);
	for (int i = 0; i < N; ++i) cin >> A[i];
	for (int i = 0; i < M; ++i) cin >> B[i];

	vector<long long> a, b;
	a.push_back(0);
	b.push_back(0);
	for (int i = 0; i < N; ++i) a.push_back(a[i] + A[i]);
	for (int i = 0; i < M; ++i) b.push_back(b[i] + B[i]);

	int maxNum = 0, num = M;
	for (int i = 0; i <= N; ++i)
	{
		if (a[i] > K) break;

		while (b[num] > K - a[i])
		{
			--num;
		}
		maxNum = max(maxNum, i + num);
	}

	cout << maxNum << endl;
}