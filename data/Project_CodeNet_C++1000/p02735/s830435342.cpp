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

const int maxn = 100;
const int dx[2]={+1,+0};
const int dy[2]={+0,+1};
struct box{
	int x,y,z;
};
bool vis[maxn][maxn][maxn];
int32_t main(){
	IOS
	memset(vis,0,sizeof(vis));
	int n,m;cin>>n>>m;
	vector<string>s(n);
	for(int i=0;i<n;i++){
		cin>>s[i];
	}
	queue<box>q;
	if( s[0][0] == '.' ){
		vis[0][0][0]=1;
		q.push({0,0,0});
	}else{
		vis[0][0][1]=1;
		q.push({0,0,1});
	}
	while( q.size() ){
		int x = q.front().x ;
		int y = q.front().y ;
		int z = q.front().z ;
		q.pop();
		for(int k=0;k<2;k++){
			int x1 = x + dx[k];
			int y1 = y + dy[k];
			if( x1 < n && y1 < m ){
				int z1 =  s[x][y] == '#' ? z : s[x1][y1] == '.' ? z : z +1;
				if( z1 < maxn && !vis[x1][y1][z1] ){
					vis[x1][y1][z1]=1;
					q.push({x1,y1,z1});
				}
			}
		}
	}
	for(int i=0;i<maxn;i++){
		if( vis[n-1][m-1][i] ){
			cout << i << endl;
			return 0;
		}
	}
	
	
}
 
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
