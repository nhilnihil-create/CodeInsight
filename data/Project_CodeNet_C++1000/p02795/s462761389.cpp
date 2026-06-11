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

int main()
{
	int n = read(),m = read(),x = read();
	printf("%d\n",(x+max(n,m)-1)/max(n,m));
	return 0;
}