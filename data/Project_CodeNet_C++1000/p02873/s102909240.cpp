#include <bits/stdc++.h>

#define SIS std::ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
#define lowbit(x) (x & -x)
#define PI 3.14159265358979323846264338327950L
typedef long long ll;
using namespace std;
const int MAX = 0x7ffffff;
int t;

void slove()
{
	string s;cin >> s;
	int n = s.size() + 1;
	vector<int> a(n + 1, 0);
	for(int i = 0;i < n - 1;i ++)
	{
		if(s[i] == '<')
			a[i + 1] = max(a[i] + 1 , a[i + 1]);
	}
	for(int i = n - 2;i >= 0;i --)
	{
		if(s[i] == '>')
			a[i] = max(a[i] , a[i + 1] + 1);
	}
	ll ans = 0;
	for(int i = 0;i < n;i ++)ans += a[i];
	cout << ans << endl;
}
int main()
{
	SIS;
	slove();
}