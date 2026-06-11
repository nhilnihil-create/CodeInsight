#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<map>
using namespace std;
typedef long long ll;
string S;
inline int read() {
	int x=0,f=1;char c=getchar();
	while (c<'0'||c>'9') {if (c=='-') f=-1;c=getchar();}
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x*f;
}
inline void smax(int &x,int y) {
	x=x<y?y:x;
}
inline void smin(int &x,int y) {
	x=x>y?y:x;
}
int n;
map<int,bool> mp;
int main() {
//	freopen("in.txt","r",stdin);
	mp.clear();
	n=read();
	for (register int i=1;i<=n;++i) {
		int x=read();
		if (!mp.count(x)) mp[x]=true;
		else {
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	return 0;
}