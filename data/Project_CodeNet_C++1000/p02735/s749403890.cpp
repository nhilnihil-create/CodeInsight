#include <bits/stdc++.h>

using namespace std;

int dist[100][100][2];
char board[100][100];
int h,w;

int main(void)
{
	cin.tie(0);
	ios::sync_with_stdio(false);

	cin >> h >> w;

	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			cin >> board[i][j];
		}
	}

	for(int i=0;i<h;i++)
	{
		for(int j=0;j<w;j++)
		{
			dist[i][j][0] = 1e9;
			dist[i][j][1] = 1e9;
		}
	}

	priority_queue <pair<int,pair<pair<int,int>,int>>,vector<pair<int,pair<pair<int,int>,int>>>,greater<pair<int,pair<pair<int,int>,int>>>> pque;

	if(board[0][0]=='#')
	{
		dist[0][0][1] = 1;
		pque.push(make_pair(dist[0][0][1],make_pair(make_pair(0,0),1)));
	}
	else
	{
		dist[0][0][0] = 0;
		pque.push(make_pair(dist[0][0][0],make_pair(make_pair(0,0),0)));
	}

	while(!pque.empty())
	{
		int y = pque.top().second.first.first;
		int x = pque.top().second.first.second;
		int t = pque.top().second.second;
		pque.pop();

		if(t==0)
		{
			if(y+1<h)
			{
				if(board[y+1][x]=='#')
				{
					if(dist[y+1][x][1-t] > dist[y][x][t] + 1)
					{
						dist[y+1][x][1-t] = dist[y][x][t] + 1;
						pque.push(make_pair(dist[y+1][x][1-t],make_pair(make_pair(y+1,x),1-t)));
					}
				}
				else
				{
					if(dist[y+1][x][t] > dist[y][x][t])
					{
						dist[y+1][x][t] = dist[y][x][t];
						pque.push(make_pair(dist[y+1][x][t],make_pair(make_pair(y+1,x),t)));
					}
				}
			}
			if(x+1<w)
			{
				if(board[y][x+1]=='#')
				{
					if(dist[y][x+1][1-t] > dist[y][x][t] + 1)
					{
						dist[y][x+1][1-t] = dist[y][x][t] + 1;
						pque.push(make_pair(dist[y][x+1][1-t],make_pair(make_pair(y,x+1),1-t)));
					}
				}
				else
				{
					if(dist[y][x+1][t] > dist[y][x][t])
					{
						dist[y][x+1][t] = dist[y][x][t];
						pque.push(make_pair(dist[y][x+1][t],make_pair(make_pair(y,x+1),t)));
					}
				}				
			}
		}
		else
		{
			if(y+1<h)
			{
				if(board[y+1][x]=='#')
				{
					if(dist[y+1][x][t] > dist[y][x][t])
					{
						dist[y+1][x][t] = dist[y][x][t];
						pque.push(make_pair(dist[y+1][x][t],make_pair(make_pair(y+1,x),t)));
					}
				}
				else
				{
					if(dist[y+1][x][1-t] > dist[y][x][t])
					{
						dist[y+1][x][1-t] = dist[y][x][t];
						pque.push(make_pair(dist[y+1][x][1-t],make_pair(make_pair(y+1,x),1-t)));
					}
				}
			}
			if(x+1<w)
			{
				if(board[y][x+1]=='#')
				{
					if(dist[y][x+1][t] > dist[y][x][t])
					{
						dist[y][x+1][t] = dist[y][x][t];
						pque.push(make_pair(dist[y][x+1][t],make_pair(make_pair(y,x+1),t)));
					}
				}
				else
				{
					if(dist[y][x+1][1-t] > dist[y][x][t])
					{
						dist[y][x+1][1-t] = dist[y][x][t];
						pque.push(make_pair(dist[y][x+1][1-t],make_pair(make_pair(y,x+1),1-t)));
					}
				}				
			}
		}
	}

	cout << min(dist[h-1][w-1][0],dist[h-1][w-1][1]) << '\n';

	return 0;
}