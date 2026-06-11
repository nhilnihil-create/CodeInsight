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
int n,a[N],tot,q[4];
pa p[N];
map<int,int>cnt;

int main(){
	n=read();
	For(i,1,n) cnt[a[i]=read()]++;
	for (auto i:cnt) p[++tot]=i;
	sort(p+1,p+1+tot,[](pa a,pa b){
		return a.se>b.se;
	});
	if (tot==1){
		if (p[1].fi==0) puts("Yes");
			else puts("No");
		return 0;
	}
	if (n%3) return puts("No"),0;
	if (tot==2){
		if (p[2].se!=n/3) return puts("No"),0;
		if (p[2].fi!=0) return puts("No"),0;
		return puts("Yes"),0;
	}
	if (tot!=3) return puts("No"),0;
	For(i,1,tot) if (p[i].se!=n/3) return puts("No"),0;
	For(i,1,3) q[i]=i;
	do {
		bool flag=1;
		For(i,1,3){
			int l=i==1?3:i-1,r=i==3?1:i+1;
			if ((p[q[l]].fi^p[q[r]].fi)!=p[q[i]].fi){
				flag=0;
				break;
			}
		}
		if (flag) return puts("Yes"),0;
	} while (next_permutation(q+1,q+1+tot));
	puts("No");
}