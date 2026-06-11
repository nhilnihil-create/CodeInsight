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

int A[200010];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) cin >> A[i];
	int ans = 0;
	int num = 1;
	for (int i = 0; i < N; i++) {
		if (A[i] != num) ans++;
		else num++;
	}
	if (ans == N) cout << -1 << endl;
	else cout << ans << endl;
}