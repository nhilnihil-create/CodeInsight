#include<bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;++i)
#define rrep(i,n) for(int i=n-1;i>=0;--i)
#define yesno(flg) if(flg){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define MAX_N 100001
#define i197 1000000007

using namespace std;
typedef long long ll;
typedef pair<ll,ll> P1;
typedef pair<int,int> Pi;
typedef pair<double,Pi> Pdi;
typedef pair<ll,int>Pli;
typedef pair<int,ll>Pil;
typedef pair<P1,ll> P2;
typedef pair<string,string> Ps;
const ll INF=1000000000000000001;
struct edge{int to,cost;};
int dy[]={0, 0, 1, -1};
int dx[]={1, -1, 0, 0};
struct Road{double cost;int a,b;};
struct pos{
	// 1 変数を入れる;
	ll a;
	int b;
};
vector<vector<ll> > vec(100001);
priority_queue<ll> que;

int main(){

	int n,m;
	cin>>n>>m;
	rep(i,n){
		int a,b;
		cin>>a>>b;
		vec[a].push_back(b);
	}

	ll ans=0;
	for(int i=1; i<m+1; i++){
		rep(j,vec[i].size()){
			que.push(vec[i][j]);
		}
		if(que.empty())continue;
		ans+=que.top();
		que.pop();
	}
	cout<<ans<<endl;

	return 0;
}
