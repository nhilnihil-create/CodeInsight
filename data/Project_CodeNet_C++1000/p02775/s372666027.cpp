#include <bits/stdc++.h>
#define syosu(x) fixed<<setprecision(x)
using namespace std;
typedef long long ll;
typedef unsigned int uint;
typedef unsigned long long ull;
typedef pair<int,int> P;
typedef pair<double,double> pdd;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<double> vd;
typedef vector<vd> vvd;
typedef vector<ll> vl;
typedef vector<vl> vvl;
typedef vector<string> vs;
typedef vector<P> vp;
typedef vector<vp> vvp;
typedef vector<pll> vpll;
typedef pair<int,P> pip;
typedef vector<pip> vip;
const int inf=1<<30;
const ll INF=1ll<<60;
const double pi=acos(-1);
const double eps=1e-8;
const ll mod=1e9+7;
const int dx[4]={-1,0,1,0},dy[4]={0,-1,0,1};

string s;

int main(){
	cin>>s;
	reverse(s.begin(),s.end());
	int n=s.size();
	int dp[2]={0,inf};
	for(int i=0;i<n;i++){
		int DP[2]={inf,inf},t=s[i]-'0';
		for(int j=0;j<10;j++) for(int k=0;k<2;k++){
			int I=0,x=t+j+k;
			if(x>=10) I=1;
			x%=10;
			DP[I]=min(DP[I],dp[k]+j+x%10);
		}
		dp[0]=DP[0];
		dp[1]=DP[1];
	}
	cout<<min(dp[0],dp[1]+1)<<endl;
}