#include <bits/stdc++.h>

#define SIS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define lowbit(x) (x & -x)
#define PI 3.14159265358979323846264338327950L
typedef long long ll;
using namespace std;
const int MAX = 0x7ffffff;
const int N = 100005;
int t;
int n , m , h[N];
void slove()
{
	int a , b;
	cin >> n >> m;
	vector<int> ma(n + 1);
	for(int i = 1;i <= n;i ++)
		cin >> h[i] , ma[i] = 0;
	for(int i = 0;i < m;i ++)
	{
		cin >> a >> b;
		ma[a] = max(ma[a] , h[b]);
		ma[b] = max(ma[b] , h[a]);
	}
	int ans = 0;
	for(int i = 1;i <= n;i ++)
	{
		ans += h[i] > ma[i];
	}
	cout << ans << endl;
}
int main()
{
	SIS;
	slove();
}