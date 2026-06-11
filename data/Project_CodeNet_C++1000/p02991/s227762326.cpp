#include <bits/stdc++.h>
using namespace std;
#define int long long
#define ll long long
#define FOR(i,a,b) for(int i=(a); i<=(b); i++)
#define rep(i,n) for(int i = 0; i < (n); i++)
#define loop(k) rep(author_is_masa,k)
#define chmin(a,b) if((a)>(b)) (a)=(b);
#define chmax(a,b) if((a)<(b)) (a)=(b);
#define vi vector<int>
#define pii pair<int,int>
#define all(v) (v).begin(),(v).end()
#define allr(v) (v).rbegin(),(v).rend()
#define pb push_back
#define pf push_front
int gcd(int a,int b){/*a>=0,b>=0,￢(a=b=0)*/
  while(min(a,b)>0){if(a<b)swap(a,b);a%=b;}return max(a,b);
}
int dx[]={1,0,-1,0,1,-1,-1,1};
int dy[]={0,1,0,-1,1,1,-1,-1};
const int MOD = 1e9+7;
const long long INF = 1e18+10;

/*--------------------------------------------------------------------*/

signed main(){
	int n,m;
	cin>>n>>m;
	vi to[300100];

	loop(m){
		int u,v;
		cin>>u>>v;
		u--;v--;
		to[3*u].pb(3*v+1);
		to[3*u+1].pb(3*v+2);
		to[3*u+2].pb(3*v);
	}
	int s,t;
	cin>>s>>t;
	s--;t--;

	queue<int> que;
	vi dist(3*n,INF);
	dist[3*s]=0;
	que.push(3*s);
	while(!que.empty()){
		int v=que.front();
		que.pop();
		for(auto p:to[v]){
			if(dist[p]<INF){
				continue;
			}
			dist[p]=dist[v]+1;
			que.push(p);
		}

	}
	if(dist[3*t]<INF)cout<<dist[3*t]/3<<endl;
	else cout<<-1<<endl;

	return 0;
}

