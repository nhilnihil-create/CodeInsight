#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
typedef pair<int,int> p;
int main()
{
	int n;
	while(cin>>n,n) 
	{
		priority_queue<p,vector<p>,greater<p> > q;
		int leave,arrive;
		for(int i = 0; i < n; ++i)
		{
			int h,m,s; 
			scanf(" %d:%d:%d",&h,&m,&s);
			leave=h*3600+m*60+s;
			
			scanf(" %d:%d:%d",&h,&m,&s);
			arrive=h*3600+m*60+s;
			
			q.push(p(leave,1));	
			q.push(p(arrive,-1));	
			
		}	
		int ans=0,tmp=0;
		while(!q.empty()) 
		{
			p t=q.top(); q.pop();
			if(t.second==-1) tmp--;
			else 
			{
				tmp++;
				ans=max(ans,tmp);
			}
		}
		cout<<ans<<endl;
	}
  return 0;
}