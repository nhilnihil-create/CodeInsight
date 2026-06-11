#include<algorithm>
#include<iostream>
#include<cstdlib>
#include<cstring>
#include<vector>
#include<queue>
#include<stack>
#include<cmath>
#include<list>
using namespace std;

struct cdnt{double x;double y;}; 
int n;
cdnt koch(cdnt p,cdnt q,int n)
{
	cdnt pp;pp.x=(p.x*2+q.x)/3;pp.y=(p.y*2+q.y)/3;
	cdnt qq;qq.x=(p.x+q.x*2)/3;qq.y=(p.y+q.y*2)/3;
	double vx=(q.x-p.x)/3;
	double vy=(q.y-p.y)/3;
	cdnt rr;rr.x=pp.x+vx/2-sqrt(3)*vy/2;rr.y=pp.y+sqrt(3)*vx/2+vy/2;
	if(n==0)
	{
		cout<<p.x<<" "<<p.y<<endl<<pp.x<<" "<<pp.y<<endl<<rr.x<<" "<<rr.y<<endl<<qq.x<<" "<<qq.y<<endl;
	}
	else
	{
		koch(p,pp,n-1);
		koch(pp,rr,n-1);
		koch(rr,qq,n-1);
		koch(qq,q,n-1);
	}
}

int main()
{
	cin>>n;n--;
	cdnt p;p.x=0;p.y=0;
	cdnt q;q.x=100;q.y=0;
	if(n+1)koch(p,q,n);
	else cout<<"0 0"<<endl;
	cout<<"100 0"<<endl;
	return 0;
}