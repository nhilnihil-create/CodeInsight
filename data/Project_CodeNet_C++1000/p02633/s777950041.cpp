#include <cstdio>
#include <iostream>
#define debug(...) fprintf(stderr,__VA_ARGS__)
using namespace std;
inline char nc() {
//	return getchar();
	static char buf[100000],*l=buf,*r=buf;
	return l==r&&(r=(l=buf)+fread(buf,1,100000,stdin),l==r)?EOF:*l++;
}
template<class T> void read(T &x) {
	x=0; int f=1,ch=nc();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=nc();}
	while(ch>='0'&&ch<='9'){x=x*10-'0'+ch;ch=nc();}
	x*=f;
}
int X;
inline int gcd(int a,int b) {return b==0?a:gcd(b,a%b);}
int main() {
	read(X);
	printf("%d\n",360/gcd(360,X));
	return 0;
} 