#include <bits/stdc++.h>

#define F first 
#define S second

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HI;
typedef priority_queue<int, vector<int>, greater<int> > HDI;

const int N = 100010, M = 1010;

int n, m;
PII a[N];
HI heap;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i ++ ) scanf("%d%d", &a[i].F, &a[i].S);
	sort(a, a + n);
	
	LL res = 0;
	for (int i = 0, cur = m - 1; cur >= 0; cur -- )
	{
		while (i < n && cur + a[i].F <= m)
		{
			heap.push(a[i].S);
			i ++ ;
		}
		if (heap.size())
		{
			res += heap.top();
			heap.pop();
		}
	}
	
	printf("%lld\n", res);
    return 0;
}