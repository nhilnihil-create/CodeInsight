//by szh
#include<bits/stdc++.h>
using namespace std;

#define pb push_back
#define fi first
#define SZ(x) (int((x).size()))
#define se second
#define ll long long
#define pq priority_queue
#define MP make_pair
#define pii pair<int,int>
#define mod 998244353
#define inf 0x3f3f3f3f
#define debug(x) cerr<<#x<<"="<<x<<'\n'
#define rep(i, a, b) for (int i=a; i<(b); i++)

const int maxn=3e5;

int n;
vector <int> edge[maxn];
vector <int> s;
ll tree[maxn*4],add[maxn*4];

void update(int c,int cl,int cr,int l,int r,ll val) {
	if (l<=cl&&cr<=r) {
		tree[c]+=(ll)(cr-cl+1)*val;
		add[c]+=val;
		return;
	}
	int mid=cl+cr>>1; 
	if (add[c]!=0) {
		tree[c<<1]+=(ll)(mid-cl+1)*add[c];
		add[c<<1]+=add[c];
		tree[c<<1|1]+=(ll)(cr-mid)*add[c];
		add[c<<1|1]+=add[c];
		add[c]=0;
	}
	if (l<=mid) update(c<<1,cl,mid,l,r,val); 
	if (r>mid) update(c<<1|1,mid+1,cr,l,r,val);
	tree[c]=tree[c<<1]+tree[c<<1|1];
	return;
}

int main(){
    std::ios::sync_with_stdio(false);
    memset(tree,0,sizeof(tree));
    memset(add,0,sizeof(add));
    cin>>n;
    rep(i,1,n) {
    	int u,v;
    	cin>>u>>v;
    	edge[u].pb(v);
    	edge[v].pb(u);
	}
	rep(i,1,n+1) sort(edge[i].begin(),edge[i].end());
	ll ans=0;
	rep(i,1,n+1) {
		s.clear();
		s.pb(0);
		rep(j,0,SZ(edge[i])) 
			if (edge[i][j]<i) s.pb(edge[i][j]);
		s.pb(i);
		int cur=1;
		for (int j=SZ(s)-2;j>=0;j--) update(1,1,n,s[j]+1,s[j+1],cur--);
		ans+=tree[1];
	}
	cout<<ans;
	return 0;
}