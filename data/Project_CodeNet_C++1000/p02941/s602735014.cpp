/*input
5
5 6 5 2 1
9817 1108 6890 4343 8704
*/
#include <bits/stdc++.h>
#define pb push_back
#define all(a) a.begin(), a.end()
#define sz(a) (int)a.size()
#define x first
#define y second
using namespace std;
using ll = long long;
using ld = long double;
using pii = pair<int, int>;
const int maxn = 2e5 + 100;
const int mod = 1e9 + 7;
int n, A[maxn], B[maxn];
queue<int>Q;
void tryPush(int i)
{
	int a = B[(i - 1 + n) % n];
	int b = B[(i + 1) % n];
	if(B[i] - a - b >= A[i])
		Q.push(i);
}
int main()
{
	ios_base::sync_with_stdio(false), cin.tie(0);
	cin >> n;
	for(int i = 0; i < n; i++)
		cin >> A[i];
	for(int i = 0; i < n; i++)
		cin >> B[i];
	for(int i = 0; i < n; i++)
		tryPush(i);
	ll ans = 0;
	while(sz(Q))
	{
		int i = Q.front();
		Q.pop();
		int pre = (i - 1 + n) % n, nxt = (i + 1) % n;
		int cnt = (B[i] - A[i]) / (B[pre] + B[nxt]);
		ans += cnt;
		B[i] -= cnt * (B[pre] + B[nxt]);
		tryPush(pre);
		tryPush(nxt);
	}
	bool chk = true;
	for(int i = 0; i < n; i++)
		chk &= (A[i] == B[i]);
	if(chk)
		cout << ans << "\n";
	else
		cout << "-1\n";
	return 0;
}