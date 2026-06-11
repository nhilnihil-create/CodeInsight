#include <cstdio>
typedef long long ll;
using namespace std;

ll gcd(ll a,ll b){
		if(a==0)return b;
		return gcd(b%a,a);
	}

ll lcm(ll a,ll b){
		return (a*b)/gcd(a,b);
	}	

int main(){
	ll a,b;scanf("%lld %lld",&a,&b);
	ll num = lcm(a,b);
	printf("%lld",num);
	return 0;
	}
