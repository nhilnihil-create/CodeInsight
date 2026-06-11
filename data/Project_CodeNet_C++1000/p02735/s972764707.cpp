#include <bits/stdc++.h>
#define fst first
#define snd second
#define fore(i,a,b) for(int i=a,ThxDem=b;i<ThxDem;++i)
#define pb push_back
#define ALL(s) s.begin(),s.end()
#define FIN ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0)
#define SZ(s) int(s.size())
using namespace std;
typedef long long ll;
typedef pair<int,int> ii;

int n,m;
int dp[110][110][2],a[110][110];

int solve(int x, int y, int c){
	if(x==n-1&&y==m-1) return a[x][y]!=c&&!c;
	int &r=dp[x][y][c];
	if(r>=0)return r;
	r=1e9;
	if(x+1<n) r=min(r,(a[x][y]!=c&&!c)+solve(x+1,y,a[x][y]));
	if(y+1<m) r=min(r,(a[x][y]!=c&&!c)+solve(x,y+1,a[x][y]));
	return r;
}

int main(){FIN;
	cin>>n>>m;
	fore(i,0,n){
		string s; cin>>s;
		fore(j,0,m) a[i][j]=s[j]=='#';
	}
	memset(dp,-1,sizeof(dp));
	int ans=solve(0,0,0);
	cout<<ans<<"\n";
}