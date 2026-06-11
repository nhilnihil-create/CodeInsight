#include <iostream>
#include <cstdlib>
#include <queue>
#include <cstring>

using namespace std;

typedef long long ll;

const int N=500010;
char c[N];
int ru[N],ans[N],hed[N],ver[N],nex[N],tot;
ll sum;
queue<int> q;

void add(int x,int y)
{
	tot++;
	ver[tot]=y;
	nex[tot]=hed[x];
	hed[x]=tot;
}

int main()
{
    int i,x,y;
	cin>>c;
	int n=strlen(c);
	for(i=0;i<n;i++)
    {
		if(c[i]=='<')
        {
			add(i,i+1);
			ru[i+1]++;
		}
		else
        {
			add(i+1,i);
			ru[i]++;
		}
	}
	for(i=0;i<=n;i++)
    {
		if(ru[i]==0)
        {
			ans[i]=0;
			q.push(i);
		}
	}
	while(!q.empty())
    {
		x=q.front();
		q.pop();
		for(i=hed[x];i;i=nex[i])
        {
			y=ver[i];
			ru[y]--;
            ans[y]=max(ans[y],ans[x]+1);
			if(ru[y]==0) q.push(y);
		}
	}
    for(i=0;i<=n;i++) sum+=ans[i];
	cout<<sum;
//    system("pause");
	return 0;
}
