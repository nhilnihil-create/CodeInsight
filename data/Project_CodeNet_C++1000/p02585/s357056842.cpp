#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
#define rep2(i,n) for(int i=1; i<=(n); i++)
using ll = long long;
int n, k, p[5005], c[5005], e;
bool used[5005];
ll v[5005], sm, ans=-1e9;
void chmax(ll &a, ll b){if(a<b) a=b;}
int main(){
	scanf("%d%d", &n, &k);
	rep2(i,n) scanf("%d", p+i);
	rep2(i,n) scanf("%d", c+i);
	rep2(t,n) if(!used[t]){
		v[e=1]=c[t];
		for(int u=p[t]; u!=t; used[u]=true, u=p[u], e++) v[e+1]=v[e]+c[u];
		rep2(i,e) rep2(j,e){
			int l = j-i+(j>i?0:e);
			ll sm = v[j]-v[i]+(j>i?0:v[e]);
			if(l<=k) chmax(ans,(v[e]>0?v[e]*((k-l)/e):0)+sm);
		}
	}
	printf("%lld\n", ans);
}