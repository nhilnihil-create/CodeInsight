#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
typedef long long ll;
const int N=2e5+4;
int f[10][10];
int ans[N];
inline int read() {
	int x=0;char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
inline int first(int x) {
	while (x>=10) x/=10;
	return x;
}
inline int last(int x) {
	return x%10;
}
int main() {
	int n=read();
	for (int i=1;i<10;++i) {
		ans[i]=ans[i-1]+1;
		f[i][i]=1;
	}
	for (register int i=10;i<=n;++i) {
		int a=first(i);
		int b=last(i);
		if (!b) ans[i]=ans[i-1];
		else {
			ans[i]=ans[i-1]+f[b][a]*2;
			if (a==b) ++ans[i];
			++f[a][b];
		}
	}
	printf("%d\n",ans[n]);
	return 0;
}