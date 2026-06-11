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

const int N = 55;
int n;
pa a[N];
map<pa,int>f;

int main(){
	n=read();
	For(i,1,n) a[i].fi=read(),a[i].se=read(),f[a[i]]=1;
	int ans=n;
	For(i,1,n){
		For(j,i+1,n){
			int x=a[i].fi-a[j].fi,y=a[i].se-a[j].se;
			int ret=0;
			For(k,1,n) if (!f[mp(a[k].fi+x,a[k].se+y)]) ++ret;
			ans=min(ans,ret);
		}
	}
	printf("%d\n",ans);
}