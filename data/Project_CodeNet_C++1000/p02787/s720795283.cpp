#include<iostream>
#include<iomanip>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
typedef long long ll;
#define MOD 1000000007

template<class T> inline void chmax(T& a, T b) { if (a < b) a = b; }
template<class T> inline void chmin(T& a, T b) { if (a > b) a = b; }


int main()
{
	int H, N; cin >> H >> N;
	vector<int> dp(H + 1, 1 << 30);//iダメージを与えるのに必要な最小魔力
	vector<int> A(N), B(N);
	for (int i = 0; i < N; ++i) {
		cin >> A[i] >> B[i];
	}
	dp[0] = 0;
	for (int h = 0; h <= H; ++h) {
		for (int n = 0; n < N; ++n) {
			if (h - A[n] < 0) {
				chmin(dp[min(A[n], H)], dp[0] + B[n]);
			}
			else {
				chmin(dp[min(h + A[n], H)], dp[h] + B[n]);
			}
		}
	}
	cout << dp[H] << endl;
	return 0;
}
