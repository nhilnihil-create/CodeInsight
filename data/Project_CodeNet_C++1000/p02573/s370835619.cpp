#include<bits/stdc++.h>
#pragma GCC optimize(2)
#define ll long long
#define rep(i,a,n) for(int i=a;i<=n;i++)
#define per(i,n,a) for(int i=n;i>=a;i--)
#define endl '\n'
#define eps 0.000000001
#define pb push_back
#define mem(a,b) memset(a,b,sizeof(a))
#define IO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int INF=0x3f3f3f3f;
const ll inf=0x3f3f3f3f3f3f3f3f;
const int mod=1e9+7;
const int maxn=2e5+5;
int n,m,fa[maxn];
int find(int x){
	while(fa[x]!=x) x=fa[x]=fa[fa[x]];
	return x;
}
int d[maxn];
int main(){
	scanf("%d%d",&n,&m);
	rep(i,1,n) fa[i]=i;
	rep(i,1,m){
		int u,v;scanf("%d%d",&u,&v);
		int eu=find(u),ev=find(v);
		if(eu!=ev) fa[ev]=eu;
	}
	map<int,int> mp;
	int cnt=0;
	rep(i,1,n){
		if(!mp[find(i)]) ++cnt,mp[find(i)]=cnt,d[cnt]++;
		else d[mp[find(i)]]++;
	}
	int ans=0;
	rep(i,1,cnt){
		ans=max(ans,d[i]);
	}
	cout<<ans<<endl;
}