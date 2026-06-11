#include<iostream>
#include<queue>
#include<ctype.h>
#include<cstdio>
using namespace std;
int H,W,sum,count;
int dir[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
struct node
{
	int x,y;
	int step;
	int color;
	char data;
}*map,now,next;
void BFS(int x,int y)
{
	queue<node>q;
	q.push(map[x*W+y]);
	while(!q.empty())
	{
		now=q.front();
		q.pop();
		for(int i=0;i<4;i++)
		{
			next.x=now.x+dir[i][0];
			next.y=now.y+dir[i][1];
			if(next.x>=0&&next.y>=0&&next.x<H&&next.y<W&&map[next.x*W+next.y].data!='X'&&map[next.x*W+next.y].color<count)
			{
				map[next.x*W+next.y].step=now.step+1;
				if(int(map[next.x*W+next.y].data-'0')==count)
				{
					count++;
					map[next.x*W+next.y].data='.';
					if(count>sum)
					{
						cout<<map[next.x*W+next.y].step<<endl;
						return;
					}
					map[next.x*W+next.y].color=count;
					BFS(next.x,next.y);
				}
				else
				{
					map[next.x*W+next.y].color=count;
					q.push(map[next.x*W+next.y]);
				}
				if(count>sum)return;
			}
		}
	}
}
int main()
{
	//freopen("01.txt","r",stdin);
	while(cin>>H>>W>>sum)
	{
		map=new node[H*W];
		for(int i=0;i<H;i++)
		{
			for(int j=0;j<W;j++)
			{
				cin>>map[i*W+j].data;
				map[i*W+j].x=i;
				map[i*W+j].y=j;
				map[i*W+j].color=0;
				if(map[i*W+j].data=='S')
				{
					now.x=i;
					now.y=j;
				}
			}
		}
		count=1;
		map[now.x*W+now.y].step=0;
		map[now.x*W+now.y].color=1;
		map[now.x*W+now.y].data='.';
		BFS(now.x,now.y);
	}
	return 0;
}