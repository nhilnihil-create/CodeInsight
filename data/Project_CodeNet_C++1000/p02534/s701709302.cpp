#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string.h>
#include<math.h>
using namespace std;
#define debug puts("ftyyydsb");
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define REP(i,a,b) for(int i=a;i>=b;i--)
template<class t> inline t read(t &x)
{
	char c=getchar();bool f=0;x=0;
	while(!isdigit(c)) f|=c=='-',c=getchar();
	while(isdigit(c)) x=(x<<1)+(x<<3)+(c^48),c=getchar();
	if(f) x=-x;return x;
}
template<class t,class ...A> inline void read(t &x,A &...a){
	read(x);read(a...);
}
template<class t> inline void write(t x){
	if(x<0) putchar('-'),write(-x);
	else{if(x>9) write(x/10);putchar('0'+x%10);}
}
template<class t> inline void writeputs(t x){write(x),putchar('\n');}
template<class t> inline void writeputchar(t x){write(x),putchar(' ');}
int n;
int main()
{
	read(n);
	FOR(i,1,n) 
	{
		putchar('A');
		putchar('C');
		putchar('L');
	}
	return 0;
}