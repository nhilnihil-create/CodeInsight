#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXN = 2e3+2;
struct node{
	ll a;
	int b;
}A[MAXN];
bool cmp(node A,node B)
{
	return A.a>B.a;
}
int N;
ll dp[MAXN][MAXN], ans;
int main() {
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> A[i].a; A[i].b = i;
	}
	sort(A, A+N, cmp);
	for (int i = 0;i<N;i++) {
		for (int j = 0;i+j<N;j++) {
			int cur = i+j;
			dp[i+1][j]=max(dp[i+1][j], dp[i][j]+A[cur].a*abs(A[cur].b-i));
			dp[i][j+1]=max(dp[i][j+1], dp[i][j]+A[cur].a*abs(A[cur].b-(N-1-j)));
		}
	}
	for (int i = 0;i<=N;i++) ans = max(ans, dp[i][N-i]);
	cout << ans << endl;
	return 0;
}