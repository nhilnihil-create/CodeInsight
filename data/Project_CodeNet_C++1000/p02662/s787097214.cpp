#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
typedef long long ll;
typedef double db;
typedef pair<int,int> pii;
typedef vector<int> vi;
#define check system("pause")
#define all(x) (x).begin(),(x).end()
#define de(a) cout<<#a<<" = "<<a<<endl
#define dd(a) cout<<#a<<" = "<<a<<" "
#define mp make_pair
#define pb push_back
#define fi first
#define se second
#define INF 0x3f3f3f3f
const ll mod = 998244353;
const int N = 6e3+20;
#define dep(i,a,b) for(int i=(a);i>=(b);i--)
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define mes(p,b) memset(p,b,sizeof(p))
#define sz(x) int(x.size())
int n,w;ll dp[N][N],a;
int main()
{
  	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>w;
	dp[0][0]=1;
	rep(i,1,n){
		cin>>a;
		rep(j,0,w){
			if(j>=a)
			dp[i][j]=dp[i-1][j-a]+dp[i-1][j]*2;
			else
			dp[i][j]=dp[i-1][j]*2;
			dp[i][j]%=mod;
		}
	}
	cout<<dp[n][w];
  	return 0;
}

