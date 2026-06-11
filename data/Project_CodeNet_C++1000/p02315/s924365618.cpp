#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cmath>
#include <cstring>


using namespace std;



#define FOR(i,a,b) for (int i=(a);i<(b);i++)
#define RFOR(i,a,b) for (int i=(b)-1;i>=(a);i--)
#define REP(i,n) for (int i=0;i<(n);i++)
#define RREP(i,n) for (int i=(n)-1;i>=0;i--)


#define V 1000


int v[101];
int w[101];

int dp[1001][10001];

int N;
int W;

int dfs(int i,int j){


	if(i == N){
		return 0;
	}
	else if(j < w[i]){
		return dfs(i+1,j);
	}
	else if(dp[i][j] != -1){
		return dp[i][j];
	}
	else{

		return dp[i][j] = max(dfs(i+1,j),dfs(i+1,j-w[i]) + v[i]);
	}
}


int main(){

	memset(dp,-1,sizeof(dp));


	cin >> N >> W;

	REP(i,N){
		cin >> v[i] >> w[i];
	}

	cout << dfs(0,W) << endl;

	return 0;

}