#include <iostream>
#include <iomanip>
#include <vector>
#include <cmath>
#define shosu(x) fixed<<setprecision(x)
using namespace std;

int w,h;
char field[105][105],sum;

void tmp(int x,int y){
	int vx[4]={1,0,-1,0},vy[4]={0,1,0,-1};
	for(int k=0;k<4;k++){
		int tmpx=x+vx[k],tmpy=y+vy[k];
		if(tmpx>=0&&tmpx<w&&tmpy>=0&&tmpy<h){
			if(field[tmpx][tmpy]!='!'&&sum==field[tmpx][tmpy]){
				field[tmpx][tmpy]='!';
				tmp(tmpx,tmpy);
			}
		}
	}
}

int bfs(int x,int y){
	int ans=0;
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			cin>>field[i][j];
		}
	}
	for(int i=0;i<x;i++){
		for(int j=0;j<y;j++){
			if(field[i][j]!='!'){
				sum=field[i][j];
				field[i][j]='!';
				tmp(i,j);
				ans++;
			}
		}
	}
	return ans;
}

int main(){
	while(1){
		cin>>w>>h;
		if(w==0&&h==0) break;
		cout<<bfs(w,h)<<endl;
	}
}