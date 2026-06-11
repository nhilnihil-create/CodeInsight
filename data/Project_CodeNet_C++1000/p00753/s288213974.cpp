#include <iostream>
#include <cstdio>
using namespace std;
typedef long long ll;
const ll ccc=1000000;
bool prime[ccc+1];
int cnt[ccc+1];
void makeprime(){
	ll iii,jjj;
	for(iii=0;iii<=ccc;iii++){
		prime[iii]=true;
	}
	prime[0]=false;
	prime[1]=false;
	for(iii=2;iii*iii<=ccc;iii++){
		if(prime[iii]){
			for(jjj=2*iii;jjj<=ccc;jjj+=iii){
				prime[jjj]=false;
			}
		}
	}
	for(int i=1;i<ccc;i++){
		cnt[i]=cnt[i-1];
		if(prime[i]) cnt[i]++;
	}
}
int main(){
	makeprime();
	while(true){
		int n;
		scanf("%d",&n);
		if(!n) break;
		printf("%d\n",cnt[2*n]-cnt[n]);
	}
	return 0;
}