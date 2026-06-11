#include<iostream>
#include<stack>
#include<cstring>
using namespace std;
const int MAXN=10010,MAXM=100010;
int n,m;
int to[MAXM],head[MAXN],nex[MAXM],top;
int sum[MAXN],dfn[MAXN],top1,hash[MAXN];
stack<int> s;
void add(int x,int y)
{
	nex[top]=head[x];
	head[x]=top;
	to[top++]=y;
	sum[y]++;
}

void input()
{
	memset(nex,-1,sizeof(nex));
	memset(head,-1,sizeof(head));
	cin>>n>>m;
	for(int i=0;i<m;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
	}
}

void tuopu()
{
	for(int i=0;i<n;i++)
	    if(!sum[i]) {s.push(i);dfn[top1++]=i;hash[i]=1;}
	while(!s.empty())
	{
		int tmp=s.top();
		s.pop();
		int u=head[tmp];
		while(u!=-1)
		{
			int tt=to[u];
			u=nex[u];
			if(hash[tt]) continue;
			sum[tt]--;
			if(sum[tt]==0) {s.push(tt);hash[tt]=1;dfn[top1++]=tt;}
		}
	}
}

void xxj()
{
	tuopu();
}

void output()
{
	for(int i=0;i<top1;i++)
	    cout<<dfn[i]<<'\n';
}

int main()
{
	input();
	xxj();
	output();
	return 0;
}