#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
int n;
long long a, ac = 1;
double ac2 = 1;
int main(){
	scanf("%d", &n);
	rep(i,n){
		scanf("%lld", &a);
		ac *= a;
		ac2 *= a;
		if(ac2 > 2e18){
			ac = -1;
			for(int j=i+1; j<n; j++){
				scanf("%lld", &a);
				if(a == 0) ac = 0;
			}
			break;
		}
	}
	if(ac > (long long)1e18) ac = -1;
	printf("%lld\n", ac);
}