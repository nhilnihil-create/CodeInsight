#include<bits/stdc++.h>
using namespace std;

#define int long long

inline int read()
{
	int x = 0, f = 1; char ch = getchar();
	for (; ch < '0' || ch > '9'; ch = getchar()) if (ch == '-') f = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar()) x = (x << 1) + (x << 3) + ch - '0';
	return x * f;
}

const int N = 2e5 + 5;
vector<int> a, b;
char s[N];

signed main()
{
	int n = read(), k = read(), c = read();
	scanf("%s", s + 1);
	
	for (int i = 1; i <= n; ++i) if (s[i] == 'o') a.push_back(i), i += c;
	for (int i = n; i >= 1; --i) if (s[i] == 'o') b.push_back(i), i -= c;
	for (int i = 0; i < k; ++i) if (a[i] == b[k - i - 1]) printf("%d\n", a[i]);
	
	return 0;
}
