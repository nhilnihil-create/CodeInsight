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
const int MOD = 998244353;
const ll INF = 1000000000000000000;

int K;
void bfs() {
	int cnt = 0;
	queue<ll> que;
	for (int i = 1; i <= 9; i++) {
		cnt++;
		if (cnt == K) {
			cout << i;
			return;
		}
		que.push(i);
	}
	while (true) {
		ll x = que.front();
		que.pop();
		for (int i = max(0ll, (x % 10) - 1); i <= min(9ll, (x % 10 ) + 1); i++) {
			cnt++;
			if (cnt == K) {
				cout << x * 10 + i;
				return;
			}
			que.push(x * 10 + i);
		}
	}
}
int main()
{
	cin >> K;
	bfs();
}