#include<iostream>
#include<map>
#include<vector>

using namespace std;

typedef long long ll;

struct cum_sum_lm {
	vector<int> sum;
	int N;
	cum_sum_lm() = default;
	cum_sum_lm(int _N) {
		N = _N;
		sum.resize(N + 1);
	}

	void setup(vector<int>& _ar) {
		sum.resize(_ar.size() + 1);
		for (int i = 0; i < N; i++) {
			sum[i + 1] = sum[i] + _ar[i];
		}
	}
	ll getval(int l, int r) {
		//[l, r)
		ll ret = sum[r] - sum[l];
		return ret;
	}
};

int N;
vector<int> A(300000 + 10);
vector<int> B(300000 + 10);
cum_sum_lm sum(300000 + 10);

int main() {
	cin >> N;
	ll X = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A[a]++;
		B[A[a]]++;
	}

	X = N;
	ll s = X;
	sum.setup(B);
	
	for (int i = 1; i <= N; i++) {
		ll l = 0, u = N + 1;
		while (u - l > 1) {
			long long x = (u + l) / 2;
			if (sum.getval(0, x + 1) >= i * x) l = x;
			else u = x;
		}
		cout << l << endl;
	}

	return 0;
}
