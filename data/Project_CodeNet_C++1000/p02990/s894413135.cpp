#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define REP(i,a,b) for(int i=a;i<b;i++)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define vi vector<int>
#define pb push_back
#define i197 1000000007
#define MAX_N 200002
using namespace std;

typedef long long ll;
typedef pair<int,int> Pii;
typedef pair<Pii,int> Piii;
typedef pair<int,ll> Pil;
typedef pair<ll,ll> Pll;
typedef pair<string,int> Psi;
typedef pair<Psi,int> Psii;

const int inf=1000000000;
struct edge{
	int myc,to,c,cost;
};
struct pos{
	int to,cost,color;
};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};

ll dp[2001][2001]={};

ll calc(int a,int b){
	if(dp[a][b]>=0)return dp[a][b];
	if(a<b)return 0;
	if(b==1||a==b)return 1;
	if(b==0)return 0;
	ll r=calc(a-1,b)+calc(a-1,b-1);
	r%=1000000007;
	dp[a][b]=r;
	return r;
}
int main() {
	int n,k;
	cin>>n>>k;

	rep(i,n+1){
		rep(j,n+1){
			dp[i][j]=-1;
		}
	}
	rep(i,k){
			ll r=calc(k,i+1)*(calc(n-k,i+2)+2*calc(n-k,i+1)+calc(n-k,i));
//			cout<<calc(n-k,i+2)+2*calc(n-k,i+1)+calc(n-k,i)<<endl;
			r%=1000000007;
			cout<<r<<endl;
	}
	return 0;
}
