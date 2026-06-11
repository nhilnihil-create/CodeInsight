#include <bits/stdc++.h>
#define FOR(i,a,b) for(register int i=(a);i<(b);++i)
#define ROF(i,a,b) for(register int i=(a);i>=(b);--i)
#define pi pair<int,int>
#define mk(a,b) make_pair(a,b)
#define fi first
#define se second
using namespace std;
typedef long long ll;
typedef double db;
const int maxn = 300005;
const int maxm = 100;
const int inf = 2147483647;
typedef long long ll;
const double eps = 1e-9;
const long long INF = 9223372036854775807ll;
ll qpow(ll a,ll b,ll c){ll ans=1;while(b){if(b&1)ans=ans*a%c;a=a*a%c;b>>=1;}return ans;}
int n,cnt[maxn],a[maxn],tot=1,s[maxn];
bool check(int k,int x){
	int pos=lower_bound(a+1,a+tot,x)-a;
	int ans=s[pos-1]+x*(tot-pos);
	if(ans>=k*x)return true;
	return false;
}
int main(){
	scanf("%d",&n);
	vector<int>b;
	FOR(i,0,n){
		int u;
		scanf("%d",&u);
		if(!cnt[u])b.push_back(u);
		cnt[u]++;
	}
	FOR(i,0,b.size())a[tot++]=cnt[b[i]];
	sort(a+1,a+tot);
	FOR(i,1,tot)s[i]=s[i-1]+a[i];
	FOR(i,1,n+1){
		int l=0,r=n/i,ans=0;
		while(l<=r){
			int mid=l+r>>1;
			if(mid==ans || check(i,mid)){
				l=mid+1;
				ans=mid;
			}else r=mid-1;
		}
		printf("%d\n",ans);
	}
}
