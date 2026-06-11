// cities to vapori-
// corner cases // int vs ll // cin vs scanf // clear structures // statement // doublesz
#include <bits/stdc++.h>
#define pb push_back
#define fst first
#define snd second
#define sz(x) int(x.size())
#define fill(x,v) memset(x,v,sizeof(x))
#define REP(i,a,b) for(int i = int(a); i < int(b); ++i)
#define trace(x) cout << #x << " = " << x << endl
#define fastio ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;
const int N = 2048;

char a[N][N];
int rp[N][N],lp[N][N];
int up[N][N], dw[N][N];

int main(){

	fastio;
	int n,m;
	cin >> n >> m;
	REP(i,1,n+1){
		REP(j,1,m+1){
			cin >> a[i][j];
		}
	}

	fill(rp,0); fill(lp,0);
	fill(up,0); fill(dw,0);

	for(int i = 1; i <= n; ++i){
		for(int j = m; j >= 1; --j){
			if(a[i][j] == '#') continue;
			rp[i][j] = 1 + rp[i][j+1];
		}
	}

	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(a[i][j] == '#') continue;
			lp[i][j] = 1 + lp[i][j-1];
		}
	}

	for(int j = 1; j <= m; ++j){
		for(int i = 1; i <= n; ++i){
			if(a[i][j] == '#') continue;
			up[i][j] = 1 + up[i-1][j];
		}
	}

	for(int j = 1; j <= m; ++j){
		for(int i = n; i >= 1; --i){
			if(a[i][j] == '#') continue;
			dw[i][j] = 1 + dw[i+1][j];
		}
	}

	int ans = 0;
	for(int i = 1; i <= n; ++i){
		for(int j = 1; j <= m; ++j){
			if(a[i][j] == '#') continue;
			int now = up[i][j] + dw[i][j] + rp[i][j] + lp[i][j] - 3;
			ans = max(ans,now);
		}
	}

	cout << ans << endl;

	return 0;
}
