#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int maxn = 103;

char map[maxn][maxn];
int move [][2] = {{0,1},{1,0},{0,-1},{-1,0}};
int n , m;
int ans;

void dfs ( int i , int j ){
	char temp = map[i][j];
	map[i][j] = '.';
	for(int k = 0 ; k < 4 ; k ++){
		if((i+move[k][0]>0)&&(i+move[k][0]<=n)&&(j+move[k][1]>0)&&(j+move[k][1]<=m)&&map[i+move[k][0]][j+move[k][1]]==temp){
			dfs(i+move[k][0],j+move[k][1]);
		}
	}
}



int main(void){
	while(cin>>n>>m){
		if((!n)&&(!m))break;
		ans = 0;
		for(int i = 1 ; i <= n ; i ++){
			for(int j = 1 ; j <= m ; j ++){
				cin>>map[i][j];
			}
		}
		for(int i = 1 ; i <= n ; i ++){
			for(int j = 1 ; j <= m ; j ++){
				if(map[i][j]!='.'){
					dfs(i,j);
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
		
}