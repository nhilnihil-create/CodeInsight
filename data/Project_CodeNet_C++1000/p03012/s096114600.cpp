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
int main()
{
	ll N;
	cin >> N;
	vector<ll>W(N);
	rep(N) {
		cin >> W[i];
	}
	ll ans = 10000000000;
	rep(N - 1) {
		ll a = 0;
		ll b = 0;
		for (ll k = 0; k < i + 1; k++) {
			a += W[k];
		}
		for (ll k = i + 1; k < N; k++) {
			b += W[k];
		}
		ans = min(ans, abs(a - b));
	}
	cout << ans;
}
