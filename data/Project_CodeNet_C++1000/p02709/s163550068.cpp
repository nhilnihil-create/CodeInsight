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



const int maxn = 2000+5;
int dp[maxn][maxn];
vector<pair<int,int>>a;
int n;
int solve(int l,int r){
	if( l + r == n )return 0;
	int &ans = dp[l][r];
	if( ans != -1 )return ans;
	ans = 0;
	int i = n - (l + r) - 1;
	ans = max( ans , a[i].first * abs( a[i].second - l ) + solve(l+1,r) );
	ans = max( ans , a[i].first * abs( a[i].second - (n - r -1) ) + solve(l,r+1) );
	return ans;
}
int32_t main(){
	IOS
	cin>>n;
	a = vector<pair<int,int>>(n);
	for(int i = 0 ; i < n ; i++ ){
		cin >> a[i].first; a[i].second = i;
	}
	sort(a.begin(),a.end());
	memset(dp,-1,sizeof(dp));
	cout << solve(0,0);
}
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
