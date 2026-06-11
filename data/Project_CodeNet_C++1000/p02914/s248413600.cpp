#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<string>
#include<cmath>
#include<queue>
#include<vector>
#include<sstream>
#include<algorithm>
#include<stack>
#include<bitset>
#include<map>
#include<unordered_map>
#include<set>
#define rep(i,n) for(int i=0;(i)<(n);i++)
#define rep1(i,n) for(int i=1;(i)<=(n);i++)
#define mst(a,b) memset(a,b,sizeof(a))
#define scd(a) scanf("%d",&a)
#define scdd(a,b) scanf("%d%d",&a,&b)
#define scddd(a,b,c) scanf("%d%d%d",&a,&b,&c)
#define IOS ios::sync_with_stdio(false),cin.tie(0),cout.tie(0)
#define dbg(a) cout<<"* "<< #a <<" : "<<a<<endl
#define fr first
#define se second
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pll pair<ll,ll>
#define ls x<<1
#define rs x<<1|1
#define lowbit(x) x&(-x)
#define ac cout<<ans<<endl
//#define DEBUG 0
using namespace std;
const double pi=acos(-1.0);
const double eps=1e-6;
const ull hashp=1e7+19;
const ll INF=0x3f3f3f3f3f3f3f3fll;
const int inf=0x3f3f3f3f;
const int mod=1e9+7;
const int maxn=2e5+100;
ll a[maxn];
ll p[maxn];
ll check(ll x){
	for(int i=60;~i;i--){
		if(p[i]>0&&(x&(1LL<<i)))x^=p[i];
	}
	return x;
}
void add(ll x){
	x=check(x);
	if(!x)return ;
	for(int i=60;~i;i--){
		if(x&(1LL<<i)){
			p[i]=x;
			return ;
		}
	}
}
ll getmax(){
	ll ret=0;
	for(int i=60;~i;i--){
		if((ret^p[i])>ret)ret^=p[i];
	}
	return ret;
}
void solve()
{
	int n;scd(n);
	ll ans=0;
	rep1(i,n){
		scanf("%lld",&a[i]);
		ans^=a[i];
	}
	rep1(i,n){
		a[i]&=(~ans);
		add(a[i]);
	}
	ans+=2*getmax();
	ac;
}
int main(){
    //IOS;
    //freopen("D://data.txt","r",stdin);
    solve();
    return 0;
}
