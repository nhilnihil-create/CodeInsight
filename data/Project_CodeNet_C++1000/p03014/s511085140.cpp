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

const int maxn = 2000+10;
int l[maxn][maxn],r[maxn][maxn],u[maxn][maxn],d[maxn][maxn];

int32_t main(){
	IOS
	for(int i=0;i<maxn;i++){
		for(int j=0;j<maxn;j++){
			l[i][j]=r[i][j]=u[i][j]=d[i][j]=0;
		}
	}
	int n,m;
	cin>>n>>m;
	vector<string>s(n+1);
	for(int i=1;i<=n;i++){
		cin>>s[i];s[i]='$'+s[i];
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			u[i][j] = s[i][j]=='#' ? 0 : u[i-1][j]+1;
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			d[i][j] = s[i][j]=='#' ? 0 : d[i+1][j]+1;
		}
	}
	for(int j=1;j<=m;j++){
		for(int i=1;i<=n;i++){
			l[i][j] = s[i][j]=='#' ? 0 : l[i][j-1]+1;
		}
	}
	for(int j=m;j>=1;j--){
		for(int i=1;i<=n;i++){
			r[i][j] = s[i][j]=='#' ? 0 : r[i][j+1]+1;
		}
	}
	int ans = 0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			//bug6(i,j,u[i][j],d[i][j],l[i][j],r[i][j]);
			if(s[i][j]=='.'){
				ans=max(ans,l[i][j]+r[i][j]+u[i][j]+d[i][j]-4+1);
			}
		}
	}
	cout<<ans;
 }
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
