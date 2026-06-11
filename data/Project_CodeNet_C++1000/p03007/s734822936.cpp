#include<bits/stdc++.h>
#define For(i,x,y) for (register int i=(x);i<=(y);i++)
#define FOR(i,x,y) for (register int i=(x);i<(y);i++)
#define Dow(i,x,y) for (register int i=(x);i>=(y);i--)
#define Debug(v) for (auto i:v) printf("%lld ",i);puts("")
#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define ep emplace_back
#define siz(x) ((int)(x).size())
#define all(x) (x).begin(),(x).end()
#define fil(a,b) memset((a),(b),sizeof(a))
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pa;
typedef pair<ll,ll> PA;
typedef vector<int> poly;
inline ll read(){
    ll x=0,f=1;char c=getchar();
    while ((c<'0'||c>'9')&&(c!='-')) c=getchar();
    if (c=='-') f=-1,c=getchar();
    while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
    return x*f;
}

const int N = 1e5+10;
int n;
ll a[N];

int main(){
	n=read();
	For(i,1,n) a[i]=read();
	sort(a+1,a+1+n);
	if (a[1]<0&&a[n]>=0){
		ll ans=0;
		For(i,1,n) ans+=abs(a[i]);
		printf("%lld\n",ans);
		int l=1;
		while (a[l]<0) ++l;
		For(i,l,n-1) printf("%lld %lld\n",a[1],a[i]),a[1]-=a[i];
		FOR(i,1,l) printf("%lld %lld\n",a[n],a[i]),a[n]-=a[i];
		return 0;
	}
	if (a[1]<0){
		ll ans=a[n]-a[n-1];
		For(i,1,n-2) ans+=abs(a[i]);
		printf("%lld\n",ans);
		printf("%lld %lld\n",a[n],a[n-1]),a[n]-=a[n-1];
		For(i,1,n-2) printf("%lld %lld\n",a[n],a[i]),a[n]-=a[i];
	} else {
		ll ans=-a[1];
		For(i,2,n) ans+=a[i];
		printf("%lld\n",ans);
		FOR(i,2,n) printf("%lld %lld\n",a[1],a[i]),a[1]-=a[i];
		printf("%lld %lld\n",a[n],a[1]);
	}
}