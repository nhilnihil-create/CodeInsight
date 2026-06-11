#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010, mod = 1e9 + 7;

int n;
char s[N];

int qp(int a, int b)
{
	int res = 1;
	while (b)
	{
		if (b & 1) res = (LL)res * a % mod;
		a = (LL)a * a % mod;
		b >>= 1;
	}
	return res;
}

int main()
{
	scanf("%s", s + 1);
	n = strlen(s + 1);
	
	int cnt = 0, res = 0;
	for (int i = 1; i <= n; i ++ )
		if (s[i] == '1')
		{
			res = (res + (LL)qp(2, cnt) * qp(3, n - i) % mod) % mod;
			cnt ++ ;
		}
		
	res = (res + qp(2, cnt)) % mod;
	printf("%d\n", res);
    return 0;
}