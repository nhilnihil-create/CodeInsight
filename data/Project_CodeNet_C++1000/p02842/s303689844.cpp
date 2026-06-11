#include<bits/stdc++.h>
using namespace std;

#define pb 		push_back
#define mp 		make_pair
#define prior   priority_queue
#define MOD 	1000000007
#define INF64 	(long long)1e18
#define INF 	(int)1e9
#define PI 		3.1415926535897932384626433832795 
#define ll      long long
#define ld		long double
#define ret     return
#define NUM 	1000001
const int SIZE = 2e5+4;
void fastio(){
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

void input(){
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif
}

int di[] = {-1,1,0,0}, dj[] = {0,0,-1,1};

void dfs(int i, int j, vector<string>& grid, vector<vector<bool>>& visited){
	if(grid[i][j]!='#')
		visited[i][j]=true;
	else
		return;
	for(int d=0;d<4;d++){
		int ni=i+di[d],nj=j+dj[d];
		if(ni>=0&&nj>=0&&ni<grid.size()&&nj<grid[0].size()&&grid[ni][nj]!='#'&&!visited[ni][nj]){
			visited[ni][nj]=true;
			dfs(ni,nj,grid,visited);
		}
	}
}



void solveTest(){
}

int main(){
	fastio();
	//input();

	/*int t;
	cin>>t;
	while(t--){
		solveTest();
	}*/

	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		if(int(i*1.08)==n){
			cout<<i<<endl;
			return 0;
		}
	}
	cout<<":("<<endl;
	return 0;
}
     