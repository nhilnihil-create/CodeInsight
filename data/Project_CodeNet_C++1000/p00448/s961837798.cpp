#include<cstdio>
#include<iostream>
#include<cstring>
#include<bitset> 
#include<algorithm>
using namespace std;
#define rep(x,y) for(x=0;x<(y);++x) 
#define aryclr(array,sign) memset((array),(sign),sizeof(array)) 
#define MAX(x,y) (((x)>(y))?(x):(y)) 
#define MIN(x,y) (((x)<(y))?(x):(y))
const int MAX_N=3500;
void in();
void solve();
int R,C;
bitset<10000> cc[10];//r,c
int main()
{
	while(cin>>R>>C&&R>0)
	{
		in();
		solve();
	}
	return 0;
}
void in()
{
	//scanf("%d%d",&R,&C);
	//cin>>R>>C; 
	int r,c;
	bool u;
	rep(r,R)
	{
		rep(c,C)
		{
		//	scanf("%d",&u);
			cin>>u;
			cc[r][c]=u;
		}
	}
}
void solve()
{
	int r,c,i,j;
	int mincc=0;
	int sumcc; 
	int ccc;
	rep(r,1<<R)
	{
		sumcc=0;
		rep(i,R)
		{
			if((r>>i)&1)//判断翻面 
			{
				cc[i].flip();
			}
		}
		rep(j,C)
		{
			ccc=0;
			rep(i,R)
			{
				if(cc[i][j])
				++ccc;
			}
			sumcc+=MAX(ccc,R-ccc);
		}
		mincc=MAX(mincc,sumcc);
		rep(i,R)//&#22797;原 
		{
			if((r>>i)&1)
			{
				cc[i].flip();
			}
		}
		
	}
	//printf("%d\n",mincc);
	cout<<mincc<<endl;
}