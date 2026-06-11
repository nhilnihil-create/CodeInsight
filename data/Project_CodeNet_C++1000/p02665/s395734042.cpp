#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define int long long
 const int MAX_N=1e5+2;
int cnt[MAX_N],n,suf[MAX_N];
int ans=0;

void dfs(int x,int now)
{
	ans+=now;//cout<<now<<"\n";
	if(x==n)
    {
		if(cnt[x]!=now) ans=-1;
		return ;
	}
	now-=cnt[x];
	if(now<=0)
    {
        ans=-1;
        return ;
	}
	dfs(x+1,min(now*2,suf[x+1]));
}

signed main()
{
    cin>>n;
	for(int i=0;i<=n;i++)
    {
        cin>>cnt[i];
        suf[i]=cnt[i];
    }

	for(int i=n;i>=0;i--) suf[i]+=suf[i+1];
	dfs(0,1);
	cout<<ans;
}
