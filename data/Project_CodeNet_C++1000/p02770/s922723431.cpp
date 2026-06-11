#pragma GCC optimize("Ofast")
#include<bits/stdc++.h>
#define int long long
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
#define PB push_back
#define PF push_front
#define FILL(a,b) memset(a,b,sizeof(a))
using namespace std;
int d[5005];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans,n,m,x,k,q,cnt;
	cin>>k>>q;
	rep(i,0,k)cin>>d[i];
	rep(t,0,q){
		cin>>n>>x>>m;x%=m;n--;
		ans=cnt=0;
		rep(i,0,k)ans+=d[i]%m,cnt-=(d[i]%m==0);
		ans=ans*(n/k);ans+=x;cnt=cnt*(n/k);
		rep(i,0,n%k)ans+=d[i]%m,cnt-=(d[i]%m==0);
		cout<<n+cnt-ans/m<<'\n';
	}
	RE 0;
}

