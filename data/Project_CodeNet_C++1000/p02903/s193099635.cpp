#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <algorithm>
#include <queue>
#define pii pair<int,int>
#define mp make_pair
#define fi first
#define se second

using namespace std;
typedef long long ll;
const int MAXN = 1005;
int n,m,a,b,ans[MAXN][MAXN];
priority_queue<pii> pq;
queue<pii> tmp;

int main()
{
	cin >> n >> m >> a >> b;
	int x = -1, y = -1;
	for(int i = 0; i<=n; i++)
	    for(int j = 0; j<=m; j++)
			if((2*a-m)*i-a*n==(2*b-n)*j-b*m)
				x = i, y = j;
	if(x<0)
	{
	    cout << -1 << endl;
		return 0;
	}
	for(int i = 1; i<=m; i++)
		pq.push(mp(i<=y?b:n-b,i));
	for(int i = 1; i<=n; i++)
	{
		int t = i<=x?a:m-a;
		pii now;
		for(int j = 1; j<=t; j++)
		{
			now = pq.top(), pq.pop();
			ans[i][now.se] = 1, now.fi--;
			tmp.push(now);
		}
		while(!tmp.empty())
			pq.push(tmp.front()), tmp.pop(); 
	}
	for(int i = 1; i<=n; i++)
	{
		for(int j = 1; j<=m; j++)
			printf("%d",ans[i][j]);
		printf("\n");
	}
	return 0;
}
