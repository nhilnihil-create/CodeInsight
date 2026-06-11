#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;

typedef long long int ll;
typedef vector<ll> vi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int modi = 1e9 + 7;
const int INF = 1e9 + 10;
const int mxn = 1<<20;
int t[2*mxn],lz[2*mxn];

void build(pair<int,int>* a, int v,int tl,int tr){
	if(tl==tr){
		t[v] = a[tl].se;
		// cout << a[tl].fi << " " << a[tl].se << " " << endl;
	}
	else{
		int tm = tl+tr>>1;
		build(a,v<<1,tl,tm);
		build(a,v<<1|1,tm+1,tr);
		t[v] = max(t[v<<1],t[v<<1|1]);
	}
}

void update(int v,int tl,int tr, int l , int r, int val){
	if(lz[v]!=0){
		t[v]+=lz[v];
		if(tl!=tr){
			lz[v<<1]+=lz[v];
			lz[v<<1|1]+=lz[v];
		}
		lz[v] = 0;
	}

	if(l>r || tl>r || tr<l) return;

	if(tl>=l && tr<=r){
		t[v]+=val;
		if(tl!=tr){
			lz[v<<1]+=val;
			lz[v<<1|1]+=val;
		}
		return;
	}

	int tm = tl+tr>>1;
	update(v<<1,tl,tm,l,r,val);
	update(v<<1|1,tm+1,tr,l,r,val);
	t[v] = max(t[v<<1],t[v<<1|1]);
}

int query(int v, int tl,int tr,int l, int r){

	if(l>r || tl>r || tr<l)
		return -INF;

	if(lz[v]!=0){
		t[v]+=lz[v];
		if(tl!=tr){
			lz[v<<1] += lz[v];
			lz[v<<1|1] += lz[v];
		}
		lz[v] = 0;
	}

	if(tl>=l && tr<=r){
		return t[v];
	}

	int tm = tl+tr>>1;
	return max(query(v<<1,tl,tm,l,r),query(v<<1|1,tm+1,tr,l,r));

}


bool cmp(pii a, pii b){
	return a.fi<b.fi || (a.fi == b.fi && a.se<b.se);
}

void solve(){
	int n,d,a;
	cin >> n >> d >> a;

	pair<int,int> mon[n],nmon[n];
	for(int i =0;i<n;i++){
		cin >> mon[i].fi >> mon[i].se;
		nmon[i].fi = -mon[i].fi;
		nmon[i].se = mon[i].se;
		// cout << nmon[i].fi << " " << nmon[i].se << endl;
	}
	sort(mon,mon+n,cmp);
	sort(nmon,nmon+n,cmp);
	build(mon,1,0,n-1);
	// for(int i = mxn;i<mxn+n;i++){
	// 	cout << t[i] << " val of tree" << endl;
	// }
	ll ans = 0;
	for(int i =0;i<n;i++){
		if(query(1,0,n-1,i,i)<=0)continue;
		int l = i;
		int r = upper_bound(mon,mon+n,mp(mon[i].fi + 2*d,INF)) - (mon);
		int del  = -a;
		int times = (query(1,0,n-1,l,l)+a-1)/a;
		// cout << i << " " << l << " " << r << endl;
		// cout << i << " " << l << " " << r  << "  " << times<< endl;

		ans+=times;
		del *=times;
		update(1,0,n-1,l,r-1,del);
	}
	memset(t,0,sizeof(t));
	memset(lz,0,sizeof(lz));
	build(nmon,1,0,n-1);
	for(int i =0;i<n;i++){
		// cout << nmon[i].fi << " " << nmon[i].se << endl;
	}
	ll newans = 0;
	for(int i =0;i<n;i++){
		if(query(1,0,n-1,i,i)<=0)continue;
		int l = i;
		int r = upper_bound(nmon,nmon+n,mp(nmon[i].fi + 2*d,INF)) - (nmon);
		int del  = -a;
		int times = (query(1,0,n-1,l,l)+a-1)/a;
		// cout << i << " " << l << " " << r  << "  " << times<< endl;
		newans+=times;
		del *=times;
		update(1,0,n-1,l,r-1,del);
	}
	ans = min(ans,newans);
	cout << ans << endl;

}

int main(){
	fast;
	// #ifndef ONLINE_JUDGE
	// 	freopen("input.txt","r",stdin);
	// 	freopen("output.txt","w",stdout);
	// #endif

	// int t;cin >> t;while(t--)
		solve();
}
