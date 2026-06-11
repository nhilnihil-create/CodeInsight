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

int k,q;
ll d[5005];
int main(){
	scanf("%d%d",&k,&q);
	rep(i,k) scanf("%lld",&d[i]);
	
	rep(i,q){
		ll n,x,m; scanf("%lld%lld%lld",&n,&x,&m);
		ll en = x;
		ll all = 0;
		rep(j,k){
			ll zan = n-2-j;
			if(zan < 0) continue;
			en += (zan/k+1)*(d[j]%m);
			if(d[j]%m > 0) all += (zan/k+1);
		}
		ll ans = (en/m) - (x/m);
		cout<<(all-ans)<<endl;
	}
}