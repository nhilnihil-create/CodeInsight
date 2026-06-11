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
	int N, M;
	cin >> N >> M;
	priority_queue<int> que;
	for (int i = 0; i < N; i++) {
		int A;
		cin >> A;
		que.push(A);
	}
	for (int i = 0; i < M; i++) {
		int num = que.top();
		que.pop();
		que.push(num / 2);
	}
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		int num = que.top();
		que.pop();
		ans += num;
	}
	cout << ans << endl;
}
