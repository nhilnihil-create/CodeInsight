#include<iostream>
#include<algorithm>
#include<functional>
#include<cmath>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#include<map>
#include<set>
#include<deque>
using namespace std;
#define ll long long
const int mod = 1000000007;
const ll INF = 1000000000000000000;

ll cnt[110];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		ll A;
		cin >> A;
		for (int i = 0; i < 60; i++) {
			cnt[i] += A % 2;
			A /= 2;
		}
	}
	ll ans = 0;
	ll power = 1;
	for (int i = 0; i < 60; i++) {
		ll r = N - cnt[i];
		ans += (((r * cnt[i]) % mod) * power) % mod;
		ans %= mod;
		power = power * 2 % mod;
	}
	cout << ans << endl;
}