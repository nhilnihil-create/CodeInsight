#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int MOD = 1000000007;
const int INF = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};

int main(){
	int h, w;
	cin >> h >> w;
	char grid[h][w];
	int ans = 0;
	rep(i,h)rep(j,w) cin >> grid[i][j];
	int l[h][w], r[h][w], u[h][w], d[h][w];
	rep(i,h)rep(j,w){
		if(grid[i][j]=='#') l[i][j]=0;
		else{
			if(j==0) l[i][j] = 1;
			else l[i][j] = l[i][j-1]+1;
		}
	}
	rep(i,h){
		for(int j = w-1; j >= 0; j--) {
			if(grid[i][j]=='#') r[i][j] = 0;
			else{
				if(j==w-1) r[i][j] = 1;
				else r[i][j] = r[i][j+1]+1;
			}
		}
	}
	rep(i,w){
		rep(j,h){
			if(grid[j][i]=='#') u[j][i] = 0;
			else {
				if(j==0) u[j][i] = 1;
				else u[j][i] = u[j-1][i]+1;
			}
		}
	}
	rep(i,w){
		for(int j = h-1; j >= 0; j--) {
			if(grid[j][i]=='#') d[j][i] = 0;
			else{
				if(j==h-1) d[j][i] = 1;
				else d[j][i] = d[j+1][i]+1;
			}
		}
	}

	rep(i,h)rep(j,w){
      	if(grid[i][j]=='#') continue;
		chmax(ans, l[i][j]+r[i][j]+u[i][j]+d[i][j]-3);
	}

	cout << ans << endl;
}