#include <cstdio>
#include <iostream>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
inline char gc() {
//	return getchar();
	static char buf[100000],*l=buf,*r=buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
template<class T> void rd(T &x) {
	x=0; int f=1,ch=gc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=gc();}
	x*=f;
}
typedef long long ll;
ll N,A,B;
inline ll cal(ll l,ll r) {return (r-l)/2;}
int main() {
	rd(N),rd(A),rd(B);
	if((A^B)&1) printf("%lld\n",min(cal(1,B-A)+A,cal(A+(N-B)+1,N)+(N-B)+1));
	else printf("%lld\n",cal(A,B));
	return 0;
}