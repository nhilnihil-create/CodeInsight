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
	int n,m;cin>>n>>m;
	vector<int>g[n+1];
	for(int i=1;i<=m;i++){
		int u,v;cin>>u>>v;
		g[u].push_back(v);
		//g[v].push_back(u);
	}
	int s,t;cin>>s>>t;
	int dis[n+1][3],inq[n+1][3];
	for(int i=0;i<=n;i++){
		for(int j=0;j<3;j++){
			dis[i][j]=1e15;
			inq[i][j]=0;
		}
	}
	dis[s][0]=0;
	queue<pair<int,int>>q;
	q.push({s,0});
	inq[s][0]=1;
	while( q.size() ){
		int u = q.front().first , x = q.front().second; q.pop(),inq[u][x]=0;
		for(auto v:g[u]){
			if( dis[v][(x+1)%3] > dis[u][x] + 1){
				dis[v][(x+1)%3] = dis[u][x] + 1;
				if( !inq[v][(x+1)%3] ){
					q.push({v,(x+1)%3});
					inq[v][(x+1)%3]=1;
				}
			}
		}
	}
	cout << ( dis[t][0]/3 < 1e10 ? dis[t][0]/3 : -1 ) << endl;
}
/*
 * long long or int?
 * index out of bound?
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
