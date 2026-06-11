#include <cstdio>
using ll = long long;
using namespace std;
int main(){
		ll a,b,k;scanf("%lld %lld %lld",&a,&b,&k);
		if(k<=a){
				printf("%lld %lld",a-k,b);
			}	
		else {
			if(k<=a+b){
				printf("0 %lld",b-(k-a));
			}	
			else{
				printf("0 0");
			}
		}		
		return 0;	
	}
