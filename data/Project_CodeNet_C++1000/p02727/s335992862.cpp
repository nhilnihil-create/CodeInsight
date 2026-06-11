#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N = 1e5;
int p[N+100],q[N+100];

int main()
{
	int x,y,a,b,c;
	priority_queue<int,vector<int>,greater<int> >pq1;
	priority_queue<int>pq2;
	scanf("%d%d%d%d%d",&x,&y,&a,&b,&c);
	for(int i=1;i<=a;i++){
		scanf("%d",p+i);
	}
	for(int i=1;i<=b;i++){
		scanf("%d",q+i);
	}
	for(int i=1;i<=c;i++){
		int cur;
		scanf("%d",&cur);
		pq2.push(cur);
	}
	sort(p+1,p+a+1,greater<int>());
	sort(q+1,q+b+1,greater<int>());
	ll ans = 0,cur = 0;
	for(int i=1;i<=x;i++){
		cur += p[i];
		pq1.push(p[i]);
	}
	for(int i=1;i<=y;i++){
		cur += q[i];
		pq1.push(q[i]);
	}
	ans = max(ans,cur);
	while(!pq1.empty()&&!pq2.empty())
	{
		int u = pq1.top();
		int v = pq2.top();
		pq1.pop();
		pq2.pop();
		cur += (v-u);
		ans = max(ans,cur);
	}
	printf("%lld\n",ans);
}
