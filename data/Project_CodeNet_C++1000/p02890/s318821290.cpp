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
cum_sum_lm sum;

int main() {
	cin >> N;
	ll X = 0;
	for (int i = 0; i < N; i++) {
		int a;
		cin >> a;
		A[a]++;
	}

	X = N;
	ll s = X;
	for (int i = 0; i < A.size(); i++) {
		B[A[i]]++;
	}
	sum.setup(B);
	
	cout << X << endl;
	ll cnt = 0;
	for (int k = 2; k <= N; k++) {
		while (X > 0) {
			//X*K<=取れるもの ならば今のXでOK
			if (X * k <= s + cnt * X) {
				break;
			}
			else {
				//sをX-1としたときに減る分を高速計算しておく
				s -= B[X] * X;
				cnt += B[X];
				X--;
			}
		}
		cout << X << endl;
	}
	return 0;
}
