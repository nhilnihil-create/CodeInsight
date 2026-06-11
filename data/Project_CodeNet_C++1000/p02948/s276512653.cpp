#include <bits/stdc++.h>

#define F first 
#define S second
#define PB push_back

using namespace std;

typedef long long LL;
typedef pair<int, int> PII;
typedef priority_queue<int> HEAP;
typedef priority_queue<int, vector<int>, greater<int> > RHEAP;

const int N = 100010, M = 1010;

int n, m;
PII a[N];
HEAP heap;

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i ++ ) scanf("%d%d", &a[i].F, &a[i].S);
	sort(a, a + n);
	
	int res = 0;
	for (int i = 1, j = 0; i <= m; i ++ )
	{
		while (j < n && a[j].F == i)
		{
			heap.push(a[j].S);
			j ++ ;
		}
		
		if (heap.size())
		{
			res += heap.top();
			heap.pop();
		}
	}
	printf("%d\n", res);
    return 0;
}