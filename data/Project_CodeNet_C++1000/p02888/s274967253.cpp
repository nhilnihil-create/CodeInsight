#include "bits/stdc++.h"
using namespace std;
using ll = long long;
using P = pair<int, int>;
#define PI acos(-1)
#define Mod (int)1000000007
#define INFTY (int)INT_MAX
#define Rep(i, n) for (int i = 0; i < (int)(n); i++)
#define BitRep(i, n) for (int i = 0; i < (int)(1 << n); i++)
#define All(vec) vec.begin(), vec.end()
#define Part(vec, b, e) vec.begin() + b, vec.begin() + e
#define Sum(vec) accumulate(vec.begin(), vec.end(), 0)
#define Sort(vec) sort(vec.begin(), vec.end())
#define Reverse(vec) reverse(vec.begin(), vec.end())
#define Count(vec, x) count(vec.begin(), vec.end(), x)
#define Next_permutation(vec) next_permutation(vec.begin(), vec.end())
#define Find(vec, s) vec.find(s) != vec.end()
#define Set_union(A, B, res) set_union(A.begin(), A.end(), B.begin(), B.end(), inserter(res, res.end()));
#define Set_intersection(A, B, res) set_intersection(A.begin(), A.end(), B.begin(), B.end(), inserter(res, res.end()));
#define Set_difference(A, B, res) set_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(res, res.end()));
#define Set_symmetric_difference(A, B, res) set_symmetric_difference(A.begin(), A.end(), B.begin(), B.end(), inserter(res, res.end()));

int main() {
	int N;
	cin >> N;
	vector<int> L(N);
	Rep(i, N) cin >> L[i];
	Sort(L);
	int ans = 0;
	for (int i = 0; i < N - 2; i++) {
		for (int j = i + 1; j < N - 1; j++) {
			int tmp = L[i] + L[j];
			for (int k = j + 1; k < N && tmp > L[k]; k++) ans++;
		}
	}
	cout << ans << endl;
	return 0;
}