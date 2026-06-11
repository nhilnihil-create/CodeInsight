#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
string S,T,U;
int a,b;
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
int main() {
//	freopen("in.txt","r",stdin);
	cin>>S>>T;
	cin>>a>>b;
	cin>>U;
	if (U==S) --a;
	else --b;
	cout<<a<<' '<<b<<endl;
	return 0;
}