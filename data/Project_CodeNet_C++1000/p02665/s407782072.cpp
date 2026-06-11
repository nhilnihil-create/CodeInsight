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

int A[100010];
ll V[100010];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N + 1; i++) {
		cin >> A[i];
		//A[i] = 0;
	}
	if (N == 0 && A[0] != 1) {
		cout << -1 << endl;
		return 0;
	}
	if (N == 0 && A[0] == 1) {
		cout << 1 << endl;
		return 0;
	}
	ll ans = 0;
	V[0] = 1;
	if (A[0] == 1) V[0]--;
	for (int i = 1; i < N + 1; i++) {
		V[i] = V[i - 1];
		if (V[i] < INF) V[i] *= 2;
		if(i != N) V[i] -= A[i];
	}
	if (V[N] < A[N]) {
		cout << -1 << endl;
		return 0;
	}
	V[N] = 0;
	for (int i = N - 1; i > 0; i--) {
		if (V[i] < (V[i + 1] + A[i + 1] + 1) / 2) {
			cout << -1 << endl;
			return 0;
		}
		if (V[i] > V[i + 1] + A[i + 1]) {
			V[i] = V[i + 1] + A[i + 1];
		}
	}
	for (int i = 0; i < N + 1; i++) {
		//cout << V[i] + A[i] << " " << V[i] << endl;
		ans += V[i] + A[i];
	}
	cout << ans << endl;
}
