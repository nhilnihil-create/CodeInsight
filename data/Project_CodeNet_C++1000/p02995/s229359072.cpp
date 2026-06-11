#include<cstdio>
#include<algorithm>
using namespace std;

typedef long long ll;

ll A,B;
ll C,D;

int GCD(int a,int b) {
	if(b==0)return a;
	return GCD(b,a%b);
}

int main() {
	scanf("%lld %lld %lld %lld",&A,&B,&C,&D);
	ll t1=B/C-(A-1)/C;
	ll t2=B/D-(A-1)/D;
	ll g=C*D/GCD(C,D);
	ll t3=B/g-(A-1)/g;
	printf("%lld",(B-A+1)-t1-t2+t3);
	return 0;
}
