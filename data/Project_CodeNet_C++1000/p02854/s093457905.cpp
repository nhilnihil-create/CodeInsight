#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back

int main(){
	int N;
	cin >> N;
	vector<i64> A(N);
	rep(i, N) cin >> A[i];
	vector<i64> sum_L(N+1, 0), sum_R(N+1, 0);
	for(int i = 0 ; i < N; i++) sum_L[i+1] += sum_L[i] + A[i];
	for(int i = N ; i > 0; i--) sum_R[i-1] += sum_R[i] + A[i-1];

	i64 ans = 2020202020;
	rep(i, N+1) ans = min(ans, abs(sum_L[i] - sum_R[i]));
	cout << ans << endl;
}
