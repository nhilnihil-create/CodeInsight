#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#pragma GCC optimize("unroll-loops")
#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
typedef pair<int,P> P1;
typedef pair<P,P> P2;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-7
#define INF 1000000000
#define mod 1000000007
#define fi first
#define sc second
#define rep(i,x) for(int i=0;i<x;i++)
#define repn(i,x) for(int i=1;i<=x;i++)
#define SORT(x) sort(x.begin(),x.end())
#define ERASE(x) x.erase(unique(x.begin(),x.end()),x.end())
#define POSL(x,v) (lower_bound(x.begin(),x.end(),v)-x.begin())
#define POSU(x,v) (upper_bound(x.begin(),x.end(),v)-x.begin())

int n;
ll a[200005],b[200005];
priority_queue<pair<ll,int>>S;

int main(){
	scanf("%d",&n);
	rep(i,n) scanf("%lld",&a[i]);
	rep(i,n) {
		scanf("%lld",&b[i]);
		S.push(mp(b[i],i));
	}
	ll ans = 0;
	while(S.size()){
		pair<ll,int>p = S.top(); S.pop();
		//rep(i,n) cout << b[i] << " " ; cout << endl;
		if(a[p.sc] > p.fi){
			puts("-1");
			return 0;
		}
		else if(a[p.sc] == p.fi) continue;
		
		int id = p.sc;
		ll pre = b[(id+n-1)%n];
		ll nxt = b[(id+1)%n];
		
		ll zan = p.fi-a[p.sc];
		//cout << zan << " " << (pre+nxt) << endl;
		zan = zan / (pre+nxt) * (pre+nxt);
		if(zan == 0){
		    puts("-1"); return 0;
		}
		b[id] -= zan;
		ans += zan / (pre+nxt);
		S.push(mp(b[id],id));
	}
	
	cout << ans << endl;
}