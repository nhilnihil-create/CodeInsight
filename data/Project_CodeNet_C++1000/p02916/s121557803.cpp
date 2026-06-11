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

int A[21], B[21], C[21];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)  cin >> A[i];
	for (int i = 0; i < N; i++)  cin >> B[i];
	for (int i = 0; i < N - 1; i++)  cin >> C[i];
	int ans = 0;
	for (int i = 0; i < N; i++) {
		ans += B[i];
		if (A[i] == A[i + 1] - 1)  ans += C[A[i] - 1];
	}
	cout << ans << endl;
}