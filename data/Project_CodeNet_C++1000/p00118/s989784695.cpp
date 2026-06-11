#include <iostream>
#include <string.h>
using namespace std;

char yard[102][102];
int ans=0;

void dfs(int x,int y,char c){
	if(yard[x][y]!=c) return;
    if(yard[x][y]==c) yard[x][y]='.';
	for(int i=-1;i<=1;i++){
		for(int j=-1;j<=1;j++){
			if((i==0||j==0)&&(i!=0||j!=0)){
				dfs(x+i,y+j,c);
			}
		}
	}
	return;
}
int main(){
	memset(yard,'.',sizeof(yard));
	int H,W;
	cin>>H>>W;
	while(H!=0||W!=0){
		for(int i=1;i<=H;i++){
			for(int j=1;j<=W;j++){
				cin>>yard[i][j];
			}
		}
		for(int i=1;i<=H;i++){
			for(int j=1;j<=W;j++){
				if(yard[i][j]!='.'){
					dfs(i,j,yard[i][j]);
					ans++;
				}
			}
		}
		cout<<ans<<endl;
		ans=0;
		cin>>H>>W;
	}
	
}