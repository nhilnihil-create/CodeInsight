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
int n,m,v,p,a[N];

inline bool check(int x){
	if (x<=p) return 1;
	if (a[x]+m<a[p]) return 0;
	ll s=0;
	For(i,p,n) if (i!=x) s+=min(m,(a[x]+m)-a[i]);
	return s>=1ll*m*(v-p);
}

int main(){
	n=read(),m=read(),v=read(),p=read();
	For(i,1,n) a[i]=read();
	sort(a+1,a+1+n),reverse(a+1,a+1+n);
	int l=1,r=n,ans=0;
	while (l<=r){
		int mid=l+r>>1;
		if (check(mid)) ans=mid,l=mid+1;
			else r=mid-1;
	}
	printf("%d\n",ans);
}