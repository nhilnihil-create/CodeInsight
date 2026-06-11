#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define ll long long
using namespace std;
template <class T>
inline void rd(T &x)
{
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)){if(c=='-')f=-1; c=getchar();}
	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
const int N=510;
int a[N][N],n;
int main() {
	rd(n);
	for(int i=0;i<n;++i,puts(""))
		for(int j=i+1;j<n;++j) {
			for(int k=0;;++k)
				if(((i>>k)&1)^((j>>k)&1)) { printf("%d ",k+1); break; }
		}
	return 0;
}