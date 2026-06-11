#include <bits/stdc++.h>
using ll = long long;
using namespace std;
#define rep(i,n) for(int i=0, i##_len=(int)(n); i<i##_len; i++)
#define reps(i,n) for(int i=1 , i##_len=(int)(n);i<=i##_len;i++)
#define rrep(i,n) for(int i=((int)(n)-1);i>=0;i--)
#define rreps(i,n) for(int i=((int)(n));i>0;i--)
#define repi(i,x) for(auto i=(x).begin(),i##_fin=(x).end();i!=i##_fin;i++)
#define all(x) (x).begin(), (x).end()
#define F first
#define S second
#define mp make_pair
#define pb push_back
#define solve(a) ((a)?"Yes":"No")
typedef vector<int> Vi;
typedef vector<Vi> VVi;
typedef pair<int , int> Pi;
typedef vector<Pi> VPi;
typedef vector<long long> V;
typedef vector<V> VV;
typedef pair<long long , long long> P;
typedef vector<P> VP;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1;} return 0;}
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1;} return 0;}
const long long INFLL = 1LL<<60;
const int INF = 1<<30;
const double PI=acos(-1);
int main(){
	int n,m;
	int ans=0;
	cin >>n>>m;
	int a,b;
	int mack=0;
	int c;
	VPi data(m);
	VVi dp(m+1,Vi(1<<n,INF));
	dp[0][0]=0;
	/*
dp: [at][state]=yen
intit : INF , [0][0]=0;
find [m][2^n-1]
	*/
	rep(i,m){
		mack=0;
		cin>>a>>b;
		rep(i,b){
			cin>>c;
			c--;
			mack|=(1<<c);
		}
		data[i]=mp(a,mack);
	}
	rep(i,m){
		rep(j,1<<n){
			chmin(dp[i+1][j],dp[i][j]);
			chmin(dp[i+1][j|data[i].S],dp[i][j]+data[i].F);
		}
	}
	if(dp[m][(1<<n )-1]==INF){
		cout<<-1<<endl;
	}else{
		cout<<dp[m][(1<<n)-1]<<endl;
	}
	//cout<<ans<<endl;
}