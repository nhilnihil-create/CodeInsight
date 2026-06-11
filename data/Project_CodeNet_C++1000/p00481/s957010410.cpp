#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

typedef pair<int,int> P;
int flg[1000][1000];

void ini(int x,int y){
	for(int k=0;k<y;k++){for(int j=0;j<x;j++){flg[k][j]=-1;}}
}

int main()
{
	int x,y,n,sum=0;
	char map[1000][1001];
	char ntoi[10]="123456789";	
	queue<P> q;
	int dx[4]={0,0,-1,1},dy[4]={-1,1,0,0};

	cin>>y>>x>>n;
	for(int i=0;i<y;i++)
	{
		for(int j=0;j<x;j++)
		{
			cin>>map[i][j];
			if(map[i][j]=='S')
			{
				q.push(make_pair(i,j));
			}
		}
	}
	for(int i=0;i<n;i++)
	{
		ini(x,y);
		flg[q.front().first][q.front().second]=0;
		while(!q.empty())
		{
			P temp=q.front();
			q.pop();
			if(map[temp.first][temp.second]==ntoi[i])
			{
				sum+=flg[temp.first][temp.second];
				while(!q.empty()){q.pop();}
				q.push(temp);
				break;
			}
			for(int j=0;j<4;j++)
			{
				if(temp.first+dy[j]>-1&&temp.first+dy[j]<y&&temp.second+dx[j]>-1&&temp.second+dx[j]<x&&map[temp.first+dy[j]][temp.second+dx[j]]!='X'&&flg[temp.first+dy[j]][temp.second+dx[j]]==-1)
				{
					flg[temp.first+dy[j]][temp.second+dx[j]] = flg[temp.first][temp.second]+1;
					q.push(make_pair(temp.first+dy[j],temp.second+dx[j]));
				}
			}
		}
	}
	cout<<sum<<endl;
	return 0;
}