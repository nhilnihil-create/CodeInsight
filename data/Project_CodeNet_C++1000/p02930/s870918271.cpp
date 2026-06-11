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

int a[510][510];
inline void solve(int l,int r,int dep){
	if (l==r) return;
	if (r-l+1==2) return a[l][r]=a[r][l]=dep,void(0);
	int mid=l+r>>1;
	solve(l,mid,dep+1),solve(mid+1,r,dep+1);
	For(i,l,mid) For(j,mid+1,r) a[i][j]=dep;
}

int main(){
	int n=read();
	solve(1,n,1);
	FOR(i,1,n){
		For(j,i+1,n) printf("%d ",a[i][j]);
		puts("");
	}
}