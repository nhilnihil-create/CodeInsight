#include<iostream>
#include<cstring>
#include<queue>
using namespace std;
struct p{
	int x;
	int y;
	int cnt;
};

int maps[1000][1000]={};
char map[1000][1000]={};
bool mapb[1000][1000]={},used[1000][1000]={};

int main(){
	queue<p> m;
	p f;
	p v;
	int h,w,n,i,j,z,sp=1,mv[4][2]={{0,-1},{1,0},{0,1},{-1,0}},count=0;
	char u,math[10]="123456789";
	cin>>h>>w>>n;
	for(i=0;i<h;i++){
		for(j=0;j<w;j++){
			cin>>u;
			for(z=0;z<9;z++){
				if(u==math[z]){
					maps[i][j]=z+1;
					mapb[i][j]=true;
				}
			}
			map[i][j]=u;
			if(u=='S'){
				f.x=j;
				f.y=i;
				f.cnt=0;
				m.push(f);
			}
		}
	}
	while(1){
		f=m.front();
		m.pop();
		if(used[f.y][f.x]==true){
			continue;
		}
		else{
			used[f.y][f.x]=true;
		}
		if(mapb[f.y][f.x]==true&&maps[f.y][f.x]<=sp){
			mapb[f.y][f.x]=false;
			count++;
			sp++;
			memset(used,0,sizeof(used));
			while(!m.empty()){
				m.pop();
			}
			m.push(f);
			used[f.y][f.x]=true;
			if(count==n){
				break;
			}
		}
		for(i=0;i<4;i++){
			if(map[f.y+mv[i][1]][f.x+mv[i][0]]!='X'&&(f.x+mv[i][0])>=0&&(f.x+mv[i][0])<w&&(f.y+mv[i][1])>=0&&(f.y+mv[i][1])<h){
				v.x=f.x+mv[i][0];
				v.y=f.y+mv[i][1];
				v.cnt=f.cnt+1;
				m.push(v);
			}
		}
	}
	cout<<f.cnt<<endl;
	return 0;
}