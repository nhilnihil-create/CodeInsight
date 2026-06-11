#include<bits/stdc++.h> 
using namespace std; 
#define x first
#define y second
#define forn(i, n) for(int i = 0; i < int(n); ++i)
typedef pair<int, int> pii;
const int MAX = 100+10;

char grid[MAX][MAX];
int path[MAX][MAX];
void solve(){
	int H,W;
	cin>>H>>W;
	forn(i,H){
		cin>>grid[i];
	}
	if(grid[0][0] =='.'){
		path[0][0] = 0;
	}
	else{
		path[0][0] = 1;
	}
	for(int i = 1;i<W;i++){
		if(grid[0][i] == '.'){
			path[0][i] = path[0][i-1];
		}
		else{
			if(grid[0][i-1] == '.'){
				path[0][i] = path[0][i-1]+1;
			}
			else{
				path[0][i] = path[0][i-1];
			}
		}
	}
	for(int i = 1;i<H;i++){
		if(grid[i][0] == '.'){
			path[i][0] = path[i-1][0];
		}
		else{
			if(grid[i-1][0] == '.'){
				path[i][0] = path[i-1][0]+1;
			}
			else{
				path[i][0] = path[i-1][0];
			}
		}
	}
	for(int i = 1 ;i<H;i++){
		for(int j = 1;j<W;j++){
			if(grid[i][j] == '.'){
				path[i][j] = min(path[i-1][j],path[i][j-1]);
			}
			else{
				int p , q;
				if(grid[i-1][j] == '.'){
					p = path[i-1][j] +1;
				}
				else{
					p = path[i-1][j];
				}
				if(grid[i][j-1] == '.'){
					 q = path[i][j-1] +1;
				}
				else{
					q = path[i][j-1];
				}
				path[i][j] = min(p,q);
			}
		}
	}
	cout<<path[H-1][W-1]<<endl;
	
}
int main(){
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	
	solve();
	
	return 0;	
}