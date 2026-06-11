#include<bits/stdc++.h>
#define LL long long
#define fr(i,x,y) for(int i=(x);i<=(y);i++)
#define rf(i,x,y) for(int i=(x);i>=(y);i--)
#define frl(i,x,y) for(int i=(x);i<(y);i++)
using namespace std;
const int N=1002;
LL S;

void read(LL &x){ scanf("%lld",&x); }

int main(){
	read(S);
	LL x=sqrt(S)+0.0001,y=S/x;
	if (x*y<S) x++;
	LL v=x*y-S;
	LL a=x-1,b=y-v;
	printf("%lld %lld %lld %lld %lld %lld\n",a,0,0,b,x,y);
	return 0;
}
