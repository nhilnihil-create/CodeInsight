#include<bits/stdc++.h>
using namespace std;
#define Fast ios::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define int long long
typedef vector<int>Vl;
typedef pair<int,int>pii;
typedef vector<pii>Vll;
typedef vector<pair<int,pii> >Vlll;
typedef priority_queue<int>PQL;
typedef map<int,int>M;
#define S second
#define F first
#define mp make_pair
#define ms(x,y) memset(x,y,sizeof(x))
#define pb push_back
#define sl(n) cin>>n
#define pl(n) cout<<n
const int mod=1e9+7;
const int sze=1e5+2;
const int inf= (int)(1e19+10LL);
int dx[2]={1,0};
int dy[2]={0,1};
int n,m;
char str[102][102];
void solve()
{
  sl(n);sl(m);
  for(int i=1;i<=n;i++){
	  for(int j=1;j<=m;j++){
		  sl(str[i][j]);
	  }
  }
  vector<vector<int>> dp(n+1, vector<int>(m+1, inf));
  dp[1][1]=(str[1][1]=='.')?0:1;
  for(int i=1;i<=n;i++){
	  for(int j=1;j<=m;j++){
		  for(int dir=0;dir<2;dir++){
	           int nx=i+dx[dir];
	           int ny=j+dy[dir];
	           if(!(nx<=n && ny<=m))continue;
	           if(str[i][j]=='.' && str[nx][ny]=='#'){
				   dp[nx][ny]=min(dp[nx][ny],dp[i][j]+1);
			   }	
			   else{
				   dp[nx][ny]=min(dp[nx][ny],dp[i][j]);
			   }	  
			  
		  }
	  }
	  
  }
  cout<<dp[n][m]<<endl;
  
  
}
 
signed main(){
   int test=1;
   //sl(test);
   while(test--){
      solve();
 
   }
  return 0;
}
