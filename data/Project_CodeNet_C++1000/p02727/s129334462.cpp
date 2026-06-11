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


int a[100010], b[100010], c[100010];
int main()
{
	int X, Y, A, B, C;
	cin >> X >> Y >> A >> B >> C;
	for (int i = 0; i < A; i++) cin >> a[i];
	for (int i = 0; i < B; i++) cin >> b[i];
	for (int i = 0; i < C; i++) cin >> c[i];
	sort(a, a + A,greater<int>());
	sort(b, b + B,greater<int>());
	vector<int> V;
	for (int i = 0; i < X; i++) V.push_back(a[i]);
	for (int i = 0; i < Y; i++) V.push_back(b[i]);
	for (int i = 0; i < C; i++) V.push_back(c[i]);
	sort(V.rbegin(), V.rend());
	ll ans = 0;
	for (int i = 0; i < X + Y; i++) {
		ans += V[i];
	}
	cout << ans << endl;
}