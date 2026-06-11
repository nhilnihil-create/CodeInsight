#include<iostream>
#include<iomanip>
#include<iomanip>
#include<string>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
#define INF (1<<30)
#define INFLL (1LL << 60)
#define MOD 1000000007
#define rep(i, n) for(int i=0; i<(n); ++i)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; }return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; }return false; }

unsigned int dp[10001];	//[ダメージ]:=消費魔力
int main()
{
	int H, N; cin >> H >> N;
	vector<int> A(N), B(N);
	rep(i, N) cin >> A[i] >> B[i];

	memset(dp, -1, sizeof(dp));
	dp[0] = 0;
	for (int i = 0; i < N; ++i) {
		for (int m = 0; m <= H; ++m) {
			if (dp[m] != -1) {
				chmin(dp[min(H, m + A[i])], dp[m] + B[i]);
			}
		}
	}
	cout << dp[H] << endl;
	return 0;
}
