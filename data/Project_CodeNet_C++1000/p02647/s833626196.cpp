#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using pll = pair<ll, ll>;
using pii = pair<int, int>;
#define ALL(x) (x).begin(), (x).end()

int main()
{
	int N, K;
	cin >> N >> K;
	vector<ll> A(N + 1, 0);
	for (int i = 1; i <= N; i++)
		cin >> A[i];

	vector<ll> out(N + 1);

	if (K <= 100) {
		for (int k = 0; k < K; k++)
		{
			for (int i = 0; i <= N; i++)
				out[i] = 0;

			for (int i = 1; i <= N; i++)
			{
				if (i - A[i] >= 0)
					out[i - A[i]]++;
				else
					out[0]++;

				if (i + A[i] + 1 <= N)
					out[i + A[i] + 1]--;
			}

			for (int i = 1; i <= N; i++)
			{
				out[i] += out[i - 1];
				A[i] = out[i];
			}
		}

		for (int i = 1; i <= N; i++)
			cout << out[i] << ((i == N) ? '\n' : ' ');
	} else {
		for (int i = 1; i <= N; i++)
			cout << N << ((i == N) ? '\n' : ' ');
	}
}