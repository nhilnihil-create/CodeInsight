#include<bits/stdc++.h>
using namespace std;
#define fi first
#define se second
const int N=10005;
int dis[105][105];char ch[105][105];
int dx[4]={0,-1,0,1};
int dy[4]={1,0,-1,0};
int H,W;
void bfs(){
	for(int i=1;i<=H;++i)
		for(int j=1;j<=W;++j)
			dis[i][j]=114514;
	deque< pair<int,int> > q;
	dis[1][1]=(ch[1][1]=='#'?1:0);
	q.push_back(make_pair(1,1));
	while(!q.empty()){
		int x=q.front().fi,y=q.front().se,tmp;q.pop_front();
		if(y+1<=W){
			tmp=(ch[x][y]=='.' && ch[x][y+1]=='#');
			if(dis[x][y+1] > dis[x][y] + tmp){
				dis[x][y+1]=dis[x][y]+tmp;
				if(tmp) q.push_back(make_pair(x,y+1));
				else q.push_front(make_pair(x,y+1));
			} 
		} 
		if(x+1<=H){
			tmp=(ch[x][y]=='.' && ch[x+1][y]=='#');
			if(dis[x+1][y] > dis[x][y] + tmp){
				dis[x+1][y]=dis[x][y]+tmp;
				if(tmp) q.push_back(make_pair(x+1,y));
				else q.push_front(make_pair(x+1,y));
			}
		}
	}
}
int main(){
	cin>>H>>W;
	for(int i=1;i<=H;++i)
		for(int j=1;j<=W;++j)
			cin>>ch[i][j];
	bfs();
	cout<<dis[H][W];
	return 0;
}
