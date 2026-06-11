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

int main()
{
	ll N;
	cin >> N;
	if (N % 2 == 1) {
		cout << 0 << endl;
		return 0;
	}
	ll ans = 0;
	ll d = 5;
	N /= 10;
	ans += N;
	while (d <= N) {
		ans += N / d;
		d *= 5;
	}
	cout << ans << endl;
}