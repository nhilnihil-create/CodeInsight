#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;
struct k{
	int x,y,cnt;
};
int i,i2,xx,yy,X,Y,map[1001][1001],b[1001][1001],mi,st[11][3],t,cntsum=0;
int main(){
	k ii;
	queue<k> Q;
	char d,z[1001][1001];
	cin>>Y>>X>>t;
	for(i=0;i<Y;i++){
		for(i2=0;i2<X;i2++){
			map[i2][i]=0;
			cin>>d;
			switch (d){
				case 'S':
					st[0][1]=i2;
					st[0][2]=i;
					break;
				case '.':
					break;
				case 'X':
					map[i2][i]=-1;
					break;
				case '1':
					st[1][1]=i2;
					st[1][2]=i;
					break;
				case '2':
					st[2][1]=i2;
					st[2][2]=i;
					break;
				case '3':
					st[3][1]=i2;
					st[3][2]=i;
					break;
				case '4':
					st[4][1]=i2;
					st[4][2]=i;
					break;
				case '5':
					st[5][1]=i2;
					st[5][2]=i;
					break;
				case '6':
					st[6][1]=i2;
					st[6][2]=i;
					break;
				case '7':
					st[7][1]=i2;
					st[7][2]=i;
					break;
				case '8':
					st[8][1]=i2;
					st[8][2]=i;
					break;
				case '9':
					st[9][1]=i2;
					st[9][2]=i;
					break;
			}
		}
	}
	/*for(i=0;i<Y;i++){
		for(i2=0;i2<X;i2++){
			cout<<map[i2][i]<<' ';
		}
	cout<<endl;
	}
	cout<<endl;*/
	int dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
	for(int w=0;w<t;w++){
		for(int ww=0;ww<Y;ww++)for(int www=0;www<X;www++)b[www][ww]=0;
		mi=999999999;
		ii.x=st[w][1];
		ii.y=st[w][2];
		ii.cnt=0;
		Q.push(ii);
		b[st[w][1]][st[w][2]]=1;
		map[st[w+1][1]][st[w+1][2]]=2;

		while(!Q.empty()){
			for(int I=0;I<4;I++){
				ii=Q.front();
				xx=ii.x+dx[I];
				yy=ii.y+dy[I];
				if(xx>=0&&yy>=0&&xx<X&&yy<Y&&map[xx][yy]!=-1&&b[xx][yy]!=1){
					ii.x=xx;
					ii.y=yy;
					ii.cnt++;
					Q.push(ii);
					b[xx][yy]=1;
		
					/*for(i=0;i<Y;i++){
						for(i2=0;i2<X;i2++){cout<<b[i2][i]<<' ';
						}
						cout<<endl;
					}
					cout<<"x="<<ii.x<<' '<<"y="<<ii.y<<' '<<"cnt="<<ii.cnt<<endl;*/
		
				}
				if(map[ii.x][ii.y]==2){
					mi=min(mi,ii.cnt);
					//cout<<"x="<<ii.x<<' '<<"y="<<ii.y<<' '<<"cnt="<<ii.cnt<<endl;
				}
			}
			Q.pop();
		}

		map[st[w+1][1]][st[w+1][2]]=0;
		cntsum+=mi;
	}
	cout<<cntsum<<endl;
}