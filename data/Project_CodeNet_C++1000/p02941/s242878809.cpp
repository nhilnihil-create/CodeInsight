#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <iostream>
#include <algorithm>
#include <stack>
#include <queue>
#include <map>
#include <set>
#include <iomanip>
#include <assert.h>
#include <fstream>

using namespace std;

typedef long long ll;

const int MAXN = 200005;

int n;
int a[MAXN];
int b[MAXN];

ll ans;

queue<int> Q;

void check(int i)
{
	if (b[i] - b[(i - 1 + n) % n] - b[(i + 1) % n] >= a[i])
		Q.push(i);
}

int main()
{
	scanf("%d",&n);
	for (int i = 0;i < n;i++)
		scanf("%d",&a[i]);
	for (int i = 0;i < n;i++)
		scanf("%d",&b[i]);
	for (int i = 0;i < n;i++)
		check(i);
	while (!Q.empty())
	{
		int cur = Q.front(),v = b[(cur - 1 + n) % n] + b[(cur + 1) % n],t = (b[cur] - a[cur]) / v;
		Q.pop();
		b[cur] -= t * v;
		check((cur - 1 + n) % n);
		check((cur + 1) % n);
		ans += t;
	}
	for (int i = 1;i <= n;i++)
		if (b[i] != a[i])
		{
			puts("-1");
			return 0;
		}
	printf("%lld\n",ans);
	return 0;
}