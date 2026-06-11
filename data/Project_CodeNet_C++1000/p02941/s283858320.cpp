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
const int MAXN = 200005;
inline int readint()
{
	int res = 0, f = 1;
	char c = 0;
	while(!isdigit(c))
	{
		c = getchar();
		if(c=='-')
			f = -1;
	}
	while(isdigit(c))
		res = res*10+c-'0', c = getchar();
	return res*f;
}
int n,a[MAXN],b[MAXN];
inline int calc(int x)
	{ return (x+n-1)%n+1; }
priority_queue<pii> pq;

int main()
{
	n = readint();
	for(int i = 1; i<=n; i++)
		a[i] = readint();
	for(int i = 1; i<=n; i++)
		b[i] = readint();
	for(int i = 1; i<=n; i++)
		if(b[i]<a[i])
		{
			cout << -1 << endl;
			return 0;
		}
	for(int i = 1; i<=n; i++)
		if(a[i]<b[i])
			pq.push(mp(b[i],i));
	ll ans = 0;
	while(!pq.empty())
	{
		pii now = pq.top();
		pq.pop();
		int id = now.se;
		int dt = b[calc(id-1)]+b[calc(id+1)];
		//cout << "test " << id << " " << dt << endl;
		if(b[id]-a[id]<dt)
		{
			cout << -1 << endl;
			return 0;
		}
		ans += (b[id]-a[id])/dt;
		b[id] = a[id]+(b[id]-a[id])%dt;
		if(a[id]<b[id])
			pq.push(mp(b[id],id));
	}
	cout << ans << endl;
	return 0;
}
