#include <bits/stdc++.h>
#define itn int
#define gI gi

using namespace std;

typedef long long ll;

inline int gi()
{
	int f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}

inline ll gl()
{
	ll f = 1, x = 0; char c = getchar();
	while (c < '0' || c > '9') {if (c == '-') f = -1; c = getchar();}
	while (c >= '0' && c <= '9') x = x * 10 + c - '0', c = getchar();
	return f * x;
}

int n, sum[55], v[55];
map <string, int> p;
string s[55];

int main()
{
	//freopen(".in", "r", stdin);
	//freopen(".out", "w", stdout);
	n = gi();
	for (int i = 1; i <= n; i+=1) 
	{
		cin >> s[i];
		v[i] = gi();
		p[s[i]] = i;
	}
	for (int i = n - 1; i >= 1; i-=1)
	{
		sum[i] = sum[i + 1] + v[i + 1];
		//cout << sum[i] << ' ' << p[s[i]] << ' ' << s[i] << endl;
	}
	cin >> s[0];
	//cout << s[0] << ' ' << p[s[0]] << endl;
	cout << sum[p[s[0]]] << endl;
	return 0;
}

