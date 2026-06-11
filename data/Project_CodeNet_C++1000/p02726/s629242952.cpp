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

const int maxn = 2005;
vector<int>g[maxn],dis(maxn);
int n;
void spfa(int s){
	fill(dis.begin(),dis.end(),1e6);
	vector<int>inq(n+1);
	queue<int>q;
	dis[s]=0;
	q.push(s);
	inq[s]=1;
	while( q.size() ){
		int u = q.front(); q.pop(); inq[u]=0;
		for(auto v:g[u]){
			if( dis[v] > dis[u] + 1 ){
				dis[v] = dis[u] + 1;
				if( !inq[v] ){
					inq[v] = 1;
					q.push(v);
				}
			}
		}
	}
}
int32_t main(){
	IOS
	int x,y;cin>>n>>x>>y;
	for(int i=1;i<n;i++){
		g[i].push_back(i+1);
		g[i+1].push_back(i);
	}
	g[x].push_back(y);
	g[y].push_back(x);
	
	vector<int>ans(n+1);
	for(int i=1;i<=n;i++){
		spfa(i);
		for(int j=1;j<=n;j++){
			ans[ dis[j] ]++;
			//bug3(i,j,dis[j]);
		}
	}
	for(int i=1;i<n;i++){
		cout << ans[i] /2 <<" ";
	}
	cout<< endl;
	

}
/*
 * long long or int?
 * index out of bound? 
 * Tested on own test case?corner?
 * Make more general solution.
 * Read Read Read Read ....
 */
