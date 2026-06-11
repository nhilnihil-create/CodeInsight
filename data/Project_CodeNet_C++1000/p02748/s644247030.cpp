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
int A,B,n,a[N],b[N];

int main(){
	A=read(),B=read(),n=read();
	int mn1=1e9,mn2=1e9;
	For(i,1,A) a[i]=read(),mn1=min(mn1,a[i]);
	For(i,1,B) b[i]=read(),mn2=min(mn2,b[i]);
	ll ans=mn1+mn2;
	For(i,1,n){
		int x=read(),y=read(),z=read();
		ans=min(ans,(ll)a[x]+b[y]-z);
	}
	printf("%lld\n",ans);
}