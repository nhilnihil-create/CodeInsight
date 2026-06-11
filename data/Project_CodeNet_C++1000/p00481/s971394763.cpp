#include <iostream>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <numeric>
#include <vector>
#include <set>
#include <queue>

using namespace std;

int h,w,n;
char s[1252];
int mp[1252][1252];
int ys[11];
int xs[11];
bool used[1252][1252];
int dx[] = {1,0,-1,0};
int dy[] = {0,1,0,-1};

int bfs(int sy,int sx,int gy,int gx){
	queue<int> qy,qx,qdist;
	for(int i=0;i<h;i++)for(int j=0;j<w;j++)
		used[i][j]=false;
	qy.push(sy);
	qx.push(sx);
	qdist.push(0);
	used[sy][sx] = true;
	while(!qy.empty()){
		int y,x,dist;
		y = qy.front(); qy.pop();
		x = qx.front(); qx.pop();
		dist = qdist.front(); qdist.pop();
		if(gy==y && gx==x)return dist;
		for(int i=0;i<4;i++){
			int ny,nx,ndist;
			ny = y+dy[i];
			nx = x+dx[i];
			ndist = dist+1;
			if(ny<0 || ny>=h || nx<0 || nx>=w)continue;
			if(used[ny][nx])continue;
			if(mp[ny][nx]==1)continue;
			used[ny][nx] = true;
			qy.push(ny);
			qx.push(nx);
			qdist.push(ndist);
		}
	}
	return -1;
}

int main(){
	scanf("%d%d%d",&h,&w,&n);
	for(int i=0;i<h;i++){
		scanf("%s",s);
		for(int j=0;j<w;j++){
			mp[i][j] = (s[j]=='X'?1:0);
			if(s[j]!='X' && s[j]!='.'){
				if(s[j]=='S'){
					ys[0]=i;
					xs[0]=j;
				}else{
					ys[s[j]-'0']=i;
					xs[s[j]-'0']=j;
				}
			}
		}
	}
	int ans = 0;
	for(int i=0;i<n;i++){
		ans += bfs(ys[i],xs[i],ys[i+1],xs[i+1]);
	}
	printf("%d\n",ans);
	return 0;
}