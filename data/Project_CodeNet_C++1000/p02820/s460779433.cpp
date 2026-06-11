#include<bits/stdc++.h>
#define int long long
#define endl '\n'
#define IOS ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define bug1( x ) {cerr << (#x) <<"="<< x << endl;}
#define bug2( x , y ) {cerr << (#x) <<"="<< (x) << "    " << (#y) << "="<< (y) << endl;}
#define bug3( x , y , z ) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << endl;}
#define bug4( x , y , z , w) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << endl;}
#define bug5( x , y , z , w ,p) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << endl;}
#define bug6( x , y , z , w ,p , q) {cerr << (#x) <<"="<<(x) << "    " << (#y) <<"="<< (y) << "    " << (#z) <<"="<< (z) << "    " << (#w) <<"="<< w << "    " << (#p) <<"="<< p << "    " << (#q) <<"="<< q << endl;}
#define bugn( x , n ) {cerr << (#x) <<":";for(int i=0;i<n;i++)cerr << x[i] <<"  "; cerr << endl;}
#define bugnm( x , n , m ) {cerr << (#x)<<endl;for(int i=0;i<n;i++){cerr << "Row #" << i<< ":";for(int j=0;j<m;j++)cerr << x[i][j] << "   ";cerr << endl;}}
typedef long long ll;
typedef long double ld;
using namespace std;

int32_t main(){
	IOS
	int n,k;cin>>n>>k;
	int cost[3];
	for(int i=0;i<3;i++){
		cin>>cost[i];
	}
	int a[n+1];
	string s;cin>>s;
	for(int i=0;i<n;i++){
		a[i+1]=( s[i] =='r' ? 0 : s[i] =='s' ? 1 : 2 );
	}
	auto cur=[&](int i,int j){
		if( (j+1)%3 == a[i] ) return cost[j];
		return 0ll;
	};
	int dp[n+1][3];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++){
		for(int j=0;j<3;j++){
			if( i - k >= 1 ){
				dp[i][j] = max(dp[i-k][(j+1)%3],dp[i-k][(j+2)%3])+cur(i,j);
			}else{
				dp[i][j] = cur(i,j);
			}
		}
		//bug4(i,dp[i][0],dp[i][1],dp[i][2]);
	}
	int ans = 0;
	for(int j=0;j<k&&n-j>=1;j++){
		ans+=max({dp[n-j][0],dp[n-j][1],dp[n-j][2]});
	}
	cout<<ans<<endl;
}
 
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
