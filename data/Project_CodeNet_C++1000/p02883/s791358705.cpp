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

ll A[200010], F[200010];
int main()
{
	int N;
	ll K;
	cin >> N >> K;
	for (int i = 0; i < N; i++) cin >> A[i];
	for (int i = 0; i < N; i++) cin >> F[i];
	sort(A, A + N);
	sort(F, F + N, greater<ll>());
	ll ok = INF;
	ll ng = -1;
	while (abs(ok - ng) > 1) {
		ll mid = (ok + ng) / 2;
		ll sum = 0;
		for (int i = 0; i < N; i++) {
			ll time = A[i] * F[i];
			sum += max(0ll, (time - mid + F[i] - 1) / F[i]);
		}
		if (sum <= K) ok = mid;
		else ng = mid;
	}
	cout << ok << endl;
}
