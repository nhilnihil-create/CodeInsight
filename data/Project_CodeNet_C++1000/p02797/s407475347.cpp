#include<bits/stdc++.h>
#define llong long long
#define mkpr make_pair
#define x first
#define y second
#define iter iterator
#define riter reversed_iterator
#define y1 Lorem_ipsum_
#define tm dolor_sit_amet_
using namespace std;

inline int read()
{
	int x = 0,f = 1; char ch = getchar();
	for(;!isdigit(ch);ch=getchar()) {if(ch=='-') f = -1;}
	for(; isdigit(ch);ch=getchar()) {x = x*10+ch-48;}
	return x*f;
}

const int mxN = 1e5;
const int INF = 1e9;
int n,m,s;

int main()
{
	n = read(),m = read(),s = read();
	for(int i=1; i<=m; i++) printf("%d ",s);
	for(int i=m+1; i<=n; i++) printf("%d ",s==INF?s-1:s+1);
	return 0;
}