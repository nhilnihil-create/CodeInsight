#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
#define PII pair<int,int>
#define MP make_pair
#define fir first
#define sec second
#define PB push_back
#define db long double
#define ll long long
using namespace std;
template <class T>
inline void rd(T &x) {
	x=0; char c=getchar(); int f=1;
	while(!isdigit(c)) { if(c=='-') f=-1; c=getchar(); }
	while(isdigit(c)) x=x*10-'0'+c,c=getchar(); x*=f;
}
int n;
int lowbit(int x) {
	int y=1;
	while(!(x&y)) y<<=1;
	return y;
}
int main() {
	rd(n);
	int k=1; while(k<n) k<<=1;
	if(k==n) { printf("No\n"); return 0; }
	printf("Yes\n");
	printf("%d %d\n",n+1,n+2);
	printf("%d %d\n",n+2,3);
	printf("%d %d\n",3,1);
	printf("%d %d\n",1,2);
	printf("%d %d\n",2,n+3);
	for(int j=4;j+1<=n;j+=2) {
		int k=j+1;
		printf("%d %d\n",j,1);
		printf("%d %d\n",j,n+k);
		printf("%d %d\n",k,1);
		printf("%d %d\n",k,n+j);
	}
	if(!(n&1)) {
		for(int x=2;x<=n-1;++x) {
			int y=n^x^1;
			if(y>=2&&y<=n-1) {
				printf("%d %d\n",n+n,x);
				printf("%d %d\n",n,y);
				break;
			}
		}
	}
	return 0;
}
