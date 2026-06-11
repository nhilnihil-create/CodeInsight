#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

bool prime[1000005];
ll n;

int main(void){
	memset(prime,true,sizeof(prime));
	prime[0]=prime[1]=false;
	for(int i=2;i<=1000000;i++){
		if(prime[i]){
			for(int j=i*2;j<=1000000;j+=i){
				prime[j]=false;
			}
		}
	}
	scanf("%lld",&n);
	int ans=0;
	for(int i=2;i<=1000000;i++){
		if(!prime[i])continue;
		int cnt=0;
		while(n%i==0){
			n/=i;
			cnt++;
		}
		for(int k=1;;k++){
			if(cnt>=k){
				ans++;
				cnt-=k;
			}else{
				break;
			}
		}
	}
	if(n!=1LL){
		ans++;
	}
	printf("%lld\n",ans);
	return 0;
}
