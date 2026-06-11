#include<bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define forn(i,a,b) for(int i =a;i<b;i++)
#define fi first
#define se second
#define fast ios_base::sync_with_stdio(false);
using namespace std;
// typedef long long int 
typedef long long int ll;
typedef vector<ll> vi;
typedef pair<ll,ll> pii;
// typedef pair<ll,ll> pll;
const int modi = 1e9 + 7;
const long long INF = 1e9 + 10;
const ll mxn = 131072*2;
ll t[2*mxn], lz[2*mxn];

void build(pair<ll,ll>* a, int v,int tl,int tr){
	if(tl==tr){
		t[v] = a[tl].se;
		// cout << a[tl].fi << " " << a[tl].se << " " << endl;
	}
	else{
		ll tm = tl+tr>>1;
		build(a,v<<1,tl,tm);
		build(a,v<<1|1,tm+1,tr);
		t[v] = (t[v<<1]+t[v<<1|1]);
	}
}

void update(int v,int tl,int tr, int l , int r, ll val){
	

	if(l>r || tl>r || tr<l) return;

	if(lz[v]!=0){
		t[v]+=(tr-tl+1)*lz[v];
		if(tl!=tr){
			lz[v<<1]+=lz[v];
			lz[v<<1|1]+=lz[v];
		}
		lz[v] = 0;
	}

	if(tl>=l && tr<=r){
		t[v]+=(tr-tl+1)*val;
		if(tl!=tr){
			lz[v<<1]+=val;
			lz[v<<1|1]+=val;
		}
		return;
	}

	ll tm = tl+tr>>1;
	update(v<<1,tl,tm,l,r,val);
	update(v<<1|1,tm+1,tr,l,r,val);
	t[v] = (t[v<<1]+t[v<<1|1]);
}

ll query(int v, int tl,int tr,int l, int r){

	if(l>r || tl>r || tr<l)
		return 0;

	if(lz[v]!=0){
		t[v]+=(tr-tl+1)*lz[v];
		if(tl!=tr){
			lz[v<<1] += lz[v];
			lz[v<<1|1] += lz[v];
		}
		lz[v] = 0;
	}

	if(tl>=l && tr<=r){
		return t[v];
	}

	ll tm = tl+tr>>1;
	return (query(v<<1,tl,tm,l,r)+query(v<<1|1,tm+1,tr,l,r));

}


bool cmp(pii a, pii b){
	return a.fi<b.fi || (a.fi == b.fi && a.se<b.se);
}

void solve(){
	ll n,d,a;
	cin >> n >> d >> a;

	pair<ll,ll> mon[n];
	for(ll i =0;i<n;i++){
		cin >> mon[i].fi >> mon[i].se;
		// nmon[i].fi = -mon[i].fi;
		// nmon[i].se = mon[i].se;
		// cout << nmon[i].fi << " " << nmon[i].se << endl;
	}
	sort(mon,mon+n,cmp);
	// sort(nmon,nmon+n,cmp);
	build(mon,1,0,n-1);
	// for(ll i = mxn;i<mxn+n;i++){
	// 	cout << t[i] << " val of tree" << endl;
	// }
	ll ans = 0;
	for(ll i =0;i<n;i++){
		if(query(1,0,n-1,i,i)<=0LL)continue;
		int l = i;
		int r = lower_bound(mon,mon+n,mp(mon[i].fi + 2*d,INF)) - (mon);
		ll del  = -a;
		ll times = ceil((query(1,0,n-1,l,l)*1.0/a));
		// cout << i << " " << l << " " << r << endl;
		// cout << i << " " << l << " " << r  << "  " << times<< endl;

		ans+=times;
		del = -1*a* times;
		update(1,0,n-1,l,r-1,del);
	}
	// memset(t,0,sizeof(t));
	// memset(lz,0,sizeof(lz));
	// build(nmon,1,0,n-1);
	// ll newans = 0;
	// for(ll i =0;i<n;i++){
	// 	if(query(1,0,n-1,i,i)<=0)continue;
	// 	int l = i;
	// 	int r = upper_bound(nmon,nmon+n,mp(nmon[i].fi + 2*d,INF)) - (nmon);
	// 	ll del  = -a;
	// 	ll times = ceil(query(1,0,n-1,l,l)*1.0/a);
	// 	cout << i << " " << l << " " << r  << "  " << times<< endl;
	// 	newans+=times;
	// 	del *=times;
	// 	update(1,0,n-1,l,r-1,del);
	// }
	// ans = min(ans,newans);
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
