#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <climits>
using namespace std;

int main()
{
	auto& in = cin;
	int N, M, X;
	in >> N >> M >> X;
	vector<int> C(N);
	vector<vector<int>> A(N);
	for (int i = 0; i < N; ++i) {
		in >> C[i];
		A[i].resize(M);
		for (int j = 0; j < M; ++j)
			in >> A[i][j];
	}

	int total = (int)pow(2, N);
	vector<vector<int>> r(total);
	vector<int> p(total);
	for (int i = 0; i < total; ++i) {
		int price = 0;
		r[i].resize(M);
		for (int j = 0; j < N; ++j) {
			if ((1 << j) & i) {
				for (int k = 0; k < M; ++k) {
					r[i][k] += A[j][k];
				}
				price += C[j];
			}
		}
		bool ok = true;
		for (int k = 0; k < M; ++k) {
			if (r[i][k] < X) {
				ok = false;
				break;
			}
		}
		if (ok) {
			p[i] = price;
		}
		else {
			p[i] = INT_MAX;
		}
	}
	auto itMin = min_element(p.begin(), p.end());
	if (*itMin == INT_MAX)
		cout << -1;
	else
		cout << *itMin;

	return 0;
}
