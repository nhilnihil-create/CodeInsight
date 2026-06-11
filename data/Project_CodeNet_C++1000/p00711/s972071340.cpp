#include<iostream>
#include <functional>
#include<algorithm>
#include <cmath>
#include <string>
#include <map>
using namespace std;

int W,H;
char a[30][30];
void se(int x,int y,int (*re)[30],int *u){
	
	if(x<0||W<=x||y<0||H<=y||a[y][x]=='#')
		return;
	if(re[y][x]==1)
		return;
	
	re[y][x]=1;
		*u+=1;
	
	se(x+1,y,re,u);
	se(x-1,y,re,u);
	se(x,y+1,re,u);
	se(x,y-1,re,u);
}

int main(){
	int x,y;
	int x1,y1;
	while(cin>>W>>H){
		if(W!=0&&H!=0){
			int re[30][30]={0};
			int u=0;
		for(int i=0;i<H;i++){
			for(int j=0;j<W;j++){
			cin>>a[i][j];
				if(a[i][j]=='@'){
				x1=j;
				y1=i;}
			}
		}
			se(x1,y1,re,&u);
				cout<<u<<endl;
		}
		else
			break;
	}

	
}