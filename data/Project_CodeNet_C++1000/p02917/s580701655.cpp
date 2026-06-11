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

int B[110];
int main()
{
	int N;
	cin >> N;
	for (int i = 0; i < N - 1; i++) cin >> B[i];
	int ans = 0;
	ans += B[0] + B[N - 2];
	for (int i = 0; i < N - 2; i++) {
		ans += min(B[i], B[i + 1]);
	}
	cout << ans << endl;
}