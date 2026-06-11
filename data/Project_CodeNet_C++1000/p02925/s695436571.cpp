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
queue<P<int,int>> q;
int a[1005][1005],n,lst[1005],b[1005];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n;
	int x,t;
	FOR(i,1,n)rep(j,1,n)cin>>a[i][j];
	FOR(i,1,n)b[i]=1;
	rep(i,1,n){
		FOR(j,i+1,n){
			if(a[i][1]==j&&a[j][1]==i){
				q.emplace(MP(i,1));
				q.emplace(MP(j,1));
				b[i]++;b[j]++;
				lst[i]=1;lst[j]=1;
			}
		}
	}
	int ans=0,nxt,d;
	P<int,int> cur;
	while(!q.empty()){
		cur=q.front();q.pop();
		gmax(ans,cur.S);
		nxt=a[cur.F][b[cur.F]];
		if(a[nxt][b[nxt]]==cur.F){
			d=max(lst[cur.F],lst[nxt])+1;
			q.emplace(MP(cur.F,d));
			q.emplace(MP(nxt,d));
			b[nxt]++;b[cur.F]++;
			lst[cur.F]=lst[nxt]=d;
		}
	}
	FOR(i,1,n){
		if(b[i]!=n){
			cout<<-1;RE 0;
		}
	}
	cout<<ans;
	RE 0;
}


