#include<bits/stdc++.h>
#define pii pair<int,int>
#define pb push_back
#define mk make_pair
using namespace std;

vector<pii > g;

int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	if(k>(n-1)*(n-2)/2) {printf("-1");return 0;}
	for(int i=2;i<=n;++i) g.pb(mk(1,i));
	int i=2,j=3;
	k=(n-1)*(n-2)/2-k;
	while(k--) {
		g.pb(mk(i,j));
		j++;
		if(j==n+1) i++,j=i+1;
	}
	printf("%d\n",g.size());
	for(int i=0;i<g.size();++i) printf("%d %d\n",g[i].first,g[i].second);
}