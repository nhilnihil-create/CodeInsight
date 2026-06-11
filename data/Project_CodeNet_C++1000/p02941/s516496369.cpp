#include <set>
#include <cstdio>
#include <cstring>
#include <algorithm>
#define fo(i,a,b) for(int i=a;i<=b;i++)
#define fd(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

typedef long long ll;

int read() {
	char ch;
	for(ch=getchar();ch<'0'||ch>'9';ch=getchar());
	int x=ch-'0';
	for(ch=getchar();ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return x;
}

const int N=2e5+5;

#define L(x) (x==1?n:x-1)
#define R(x) (x==n?1:x+1)

set< pair<int,int> > s;

int n,a[N],b[N];

int main() {
	n=read();
	fo(i,1,n) a[i]=read();
	fo(i,1,n) b[i]=read();
	fo(i,1,n) s.insert(make_pair(-b[i],i));
	ll ans=0;
	while (!s.empty()) {
		pair<int,int> tmp=*s.begin();s.erase(s.begin());
		int x=tmp.second,cnt=b[L(x)]+b[R(x)];
		if (b[x]==a[x]) continue;
		if (b[x]<a[x]) {ans=-1;break;}
		int d=b[x]-a[x];
		if (d<cnt) {ans=-1;break;}
		ans+=d/cnt;b[x]-=d/cnt*cnt;
		s.insert(make_pair(-b[x],x));
	}
	printf("%lld\n",ans);
	return 0;
}