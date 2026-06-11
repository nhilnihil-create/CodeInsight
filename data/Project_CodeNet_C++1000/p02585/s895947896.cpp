#include <iostream>
#include <vector>

using namespace std;

int N;
long long K;
vector<int> P;
vector<long long> C;

int main()
{
	cin >> N;
	cin >> K;
	P = vector<int>(N+1);
	C = vector<long long>(N+1);
	auto f = vector<bool>(N + 1, true);
	for (int i = 1; i <= N; i++) {
		cin >> P[i];
	}
	for (int i = 1; i <= N; i++) {
		cin >> C[i];
	}

	long long ans = C[1];

	for (int i = 1; i <= N; i++) {
		if (f[i]) {
			f[i] = false;
			int sn = 1;
			long long ss = C[i];
			int p = P[i];
			auto sa = vector<int>();
			sa.push_back(i);

			while (p != i) {
				f[p] = false;
				ss += C[p];
				sn++;
				sa.push_back(p);
				p = P[p];
			}

			long long sb = 0;
			int k = sn-1;
			if (K < k) { k = (int)K; }
			if (ss > 0) {
				sb = ss * (K / (long long)sn);
				k = K % (long long)sn;

				if (k == 0) {
					sb-=ss;
					k = sn;
				}
			}

			auto ad = vector<long long>(sn,0);
			for (int j = 1; j <= k; j++) {
				for (int n = 0; n < sn; n++) {
					ad[n] += C[sa[(n+j)%sn]];

					ans = max(ans,sb + ad[n]);
				}
			}


		}
	}

	cout << ans << endl;

	return 0;
}

