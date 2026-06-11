#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<queue>
#include<map>
#include<math.h>
#include<iomanip>
#include<set>
#include<numeric>
#include<cstring>
#include<cstdio>
#include<functional>
#include<bitset>
#include<limits.h>
#include<cassert>
#include<iterator>
#include<complex>
#include<stack>
#include<sstream>
#include<iterator>
#include<list>

using namespace std;

typedef  long long int lint;

#define rep(i, n) for (lint i = 0; i < n; i++)
#define sort(v) sort((v).begin(), (v).end())
#define reverse(v) reverse((v).begin(), (v).end())
#define upper(v,hoge) upper_bound(v.begin(),v.end(),hoge)
#define lower(v,hoge) lower_bound(v.begin(),v.end(),hoge)
#define mp make_pair
#define enld endl

int main() {
	lint N, M, K;
	cin >> N >> M >> K;
	vector<lint>A(N);
	vector<lint>B(M);
	rep(i, N) {
		cin >> A[i];
	}
	rep(i, M) {
		cin >> B[i];
	}
	vector<lint>SA(N);
	vector<lint>SB(M);
	SA[0] = A[0];
	for (lint i = 1; i < N; i++) {
		SA[i] = SA[i - 1] + A[i];
	}
	SB[0] = B[0];
	for (lint i = 1; i < M; i++) {
		SB[i] = SB[i - 1] + B[i];
	}
	vector<lint>sa;
	vector<lint>sb;
	sa.push_back(0);
	sb.push_back(0);
	rep(i, N) {
		sa.push_back(SA[i]);
	}
	rep(i, M) {
		sb.push_back(SB[i]);
	}

	lint ans = 0;

	rep(i, N + 1) {
		lint j = upper(sb, K - sa[i]) - upper(sb,0);
		if (j >= 0) {
			ans = max(ans, i + j);
		}
	}
	cout << ans << endl;
}