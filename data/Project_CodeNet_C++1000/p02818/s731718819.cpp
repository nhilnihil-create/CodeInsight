#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
ll a,b,x;
inline int read() {
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
inline void smax(ll &x,ll y) {
	x=x<y?y:x;
}
int main() {
//	freopen("in.txt","r",stdin);
	cin>>a>>b>>x;
	if (x>a) {
		b-=(x-a);
		smax(b,0);
	}
	a-=x;
	smax(a,0);
	cout<<a<<' '<<b<<endl;
	return 0;
}