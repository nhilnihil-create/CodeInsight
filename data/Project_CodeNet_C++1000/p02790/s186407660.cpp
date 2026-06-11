#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
typedef long long ll;

inline int read() {
	int x=0;char c=getchar();
	while (c<'0'||c>'9') c=getchar();
	while (c>='0'&&c<='9') x=x*10+c-'0',c=getchar();
	return x;
}
string x,y;
int main() {
	string a,b;
	cin>>a>>b;
	int n=a[0]-'0',m=b[0]-'0';
	for (int i=1;i<=n;++i) x+=b;
	for (int i=1;i<=m;++i) y+=a;
	if (x<y) cout<<x<<endl;
	else cout<<y<<endl;
	return 0;
}