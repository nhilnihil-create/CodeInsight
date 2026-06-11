#include <cstdio>
#include <queue>
#define N 200005
using namespace std;

int n , s[N] , t[N];
typedef pair<int , int> pa;

priority_queue<pa> q;

int prev(int x){return x == 1 ? n : x - 1;}
int next(int x){return x == n ? 1 : x + 1;}
long long ans;
int main()
{
	scanf("%d" , &n);
	for(int i = 1 ; i <= n ; i ++) 
		scanf("%d" , t + i);
	for(int i = 1 ; i <= n ; i ++)
		scanf("%d" , s + i) , q.push( make_pair(s[i] , i) );
	while(!q.empty())
	{
		int val = q.top().first , id = q.top().second;
		q.pop();
		if(t[id] == val)  continue;
		int around = s[prev(id)] + s[next(id)];
		int cnt = (val - t[id]) / around;
		if(cnt <= 0) return puts("-1") & 0;
		ans += cnt; s[id] = val - cnt * around;
		q.push( make_pair(s[id] , id) );
	}
	return printf("%lld\n" , ans) & 0;
}