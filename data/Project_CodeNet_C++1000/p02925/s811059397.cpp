#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define ll long long
#define gmax(x,y) x=max(x,y)
#define gmin(x,y) x=min(x,y)
#define F first
#define S second
#define P pair
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define rep(i,a,b) for(int i=a;i<b;i++)
#define V vector
#define RE return
#define ALL(a) a.begin(),a.end()
#define MP make_pair
#define PB emplace_back
#define PF emplace_front
#define FILL(a,b) memset(a,b,sizeof(a))
#define lwb lower_bound
#define upb upper_bound
using namespace std;
V<int> v[1000005];
int a[1005][1005],id[1005][1005],num[1000005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n,cnt=0;
	cin>>n;
	rep(i,1,n)FOR(j,i+1,n)id[i][j]=id[j][i]=++cnt;
	FOR(i,1,n){
		rep(j,1,n)cin>>a[i][j];
		rep(j,1,n-1)v[id[i][a[i][j]]].PB(id[i][a[i][j+1]]),num[id[i][a[i][j+1]]]++;
	}
	queue<P<int,int> > q;
	FOR(i,1,cnt){
		if(!num[i]){
			q.emplace(MP(i,1));
		}
	}
	P<int,int> cur;
	int ans=0;
	while(!q.empty()){
		cur=q.front();q.pop();
		ans=max(ans,cur.S);
		for(auto u:v[cur.F]){
			num[u]--;
			if(!num[u])q.emplace(MP(u,cur.S+1));
		}
	}
	FOR(i,1,cnt){
		if(num[i]){
			cout<<-1;RE 0;
		}
	}
	cout<<ans;
	RE 0;
}


