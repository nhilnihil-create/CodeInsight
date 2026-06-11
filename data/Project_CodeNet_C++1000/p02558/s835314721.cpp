#include<bits/stdc++.h>
#include<atcoder/dsu>
using namespace std;
using namespace atcoder;

#define INF 1234567890
#define ll long long

int N, Q;

int main()
{
	scanf("%d %d", &N, &Q);
	dsu tree(N);
	while(Q--)
	{
		int t, a, b;
		scanf("%d %d %d", &t, &a, &b);
		if (t == 0)
		{
			tree.merge(a, b);
		}
		else
		{
			printf("%d\n", (int)tree.same(a, b));
		}
	}
	return 0;
}