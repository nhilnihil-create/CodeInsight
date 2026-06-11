#include <bits/stdc++.h>
using namespace std;

#define FOR(i,l,r) for(int i = (int) (l);i < (int) (r);i++)
#define ALL(x) x.begin(),x.end()
template<typename T> bool chmax(T& a,const T& b){ return a < b ? (a = b,true) : false; }
template<typename T> bool chmin(T& a,const T& b){ return b < a ? (a = b,true) : false; }
typedef long long ll;

int N,M;
vector<string> S;
bool vis [100] [100];
const int dx [] = {0,1,0,-1};
const int dy [] = {-1,0,1,0};

bool in_range(int y,int x)
{
	return y >= 0 && y < N && x >= 0 && x < M;
}

void dfs(int y,int x)
{
	if(vis [y] [x]) return;
	vis [y] [x] = true;
	FOR(i,0,4){
		int ny = y + dy [i],nx = x + dx [i];
		if(in_range(ny,nx) && S [y] [x] == S [ny] [nx]){
			dfs(ny,nx);
		}
	}
}

int main()
{
	while(cin >> N >> M,N){
		S.assign(N,"");
		FOR(i,0,N){
			cin >> S [i];
		}
		memset(vis,0,sizeof(vis));
		int ans = 0;
		FOR(i,0,N) FOR(j,0,M) if(vis [i] [j] == false){
			dfs(i,j);
			ans++;
		}
		cout << ans << endl;
	}

	return 0;
}