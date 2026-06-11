#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;

ll tc, bil, r;


int main(){
	scanf("%lld %lld",&bil, &tc);
	map<ll,ll> ar;
	for(int k = 1; k<= tc; k++){
		scanf("%lld", &r);
		ar[r]++;
	}
	ll tmp = 0;
	ll jaw = 0;
	if(tc == 0){
		printf("%lld\n", bil);
		return 0;
	}
	while(true){
		if(ar[bil - tmp] == 0){
			jaw = bil - tmp;
			break;
		}
		if(ar[bil + tmp] == 0){
			jaw = bil + tmp;
			break; 
		}
		tmp++;
	}
	printf("%lld\n",jaw);
}