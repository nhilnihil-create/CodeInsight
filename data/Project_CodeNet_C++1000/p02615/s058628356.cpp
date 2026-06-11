#include <bits/stdc++.h>
#include <cmath>
using namespace std;
typedef long long ll;

ll tc, l, r, ar[200005];


int main(){
	scanf("%lld", &tc);
	for(int k = 1; k<= tc; k++){
		scanf("%lld", &ar[k]);
	}
	sort(ar + 1, ar + tc + 1);
	ll mem = tc - 2;
	ll jaw = 0;
	jaw+=ar[tc];
	for(int k = tc - 1; k>= 1; k--){
		if(mem == 0){
			break;
		}
		jaw+=ar[k];
		mem--;
		if(mem == 0){
			break;
		}
		jaw+=ar[k];
		mem--;
	}
	printf("%lld\n",jaw);
}