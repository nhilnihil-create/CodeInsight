// kyopro.cpp : このファイルには 'main' 関数が含まれています。プログラム実行の開始と終了がそこで行われます。
//

#include <iostream>
#include<map>
#include<algorithm>
#include<set>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
using namespace std;
#define ll long long int
#define rep(N) for(ll i=0;i<N;i++)
#define For(i,N) for(ll i=0;i<N;i++)
ll MOD = 1e9 + 7;
int main()
{
	ll N;
	ll M;
	cin >> N >> M;
	vector<ll>a(M);
	rep(M)cin >> a[i];
	vector<ll>DP(N + 1);
	if (M == 0) {
		DP[0] = 1;
		DP[1] = 1;
		rep(N - 1) {
			DP[i + 2] = DP[i] + DP[i + 1];
			DP[i+2] %= MOD;
		}
	}
	else {
		DP[0] = 1;
		auto it = a.begin();
		if (*it != 1) {
			DP[1] = 1;
		}
		else if (it + 1 != a.end())
			it++;

		rep(N - 1) {
			DP[i + 2] = DP[i + 1] + DP[i];
			if (*it == i + 2) {
				DP[i + 2] = 0;
				if (it + 1 != a.end())
					it++;
			}
			DP[i + 2] %= MOD;

		}
	}
	cout << DP[N];
}
