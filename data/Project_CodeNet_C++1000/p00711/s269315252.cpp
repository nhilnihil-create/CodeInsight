#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<stack>
#include<vector>
#include<set>
#include<map>
#define INF 0x3f3f3f3f
using namespace std;
typedef long long LL;
int h,w,step;
char mp[25][25];
const int ox[]={1,-1,0,0};
const int oy[]={0,0,1,-1};

bool dfs(int X,int Y){
	for(int i=0;i<4;i++){
		int x=X+ox[i];
		int y=Y+oy[i];
		if(0<=x&&x<h&&0<=y&&y<w&&mp[x][y]=='.'){
			mp[x][y]='@';
			step++;
			dfs(x,y);
		}
	}
}

int main()
{
	while(scanf("%d%d",&w,&h)!=EOF&&(w+h)){
		for(int i=0;i<h;i++)
			scanf("%s",&mp[i]);
		step=0;
		for(int i=0;i<h;i++){
			for(int j=0;j<w;j++){
				if(mp[i][j]=='@'){
					step=1;
					dfs(i,j);
					i=w=25;
				}
			}
		}
		printf("%d\n",step);
	}
	return 0;
}