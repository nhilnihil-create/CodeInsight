#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main()
{
	ll n;
	scanf("%lld",&n);
	int ans;
	if(n!=2){
		ans = 2;
	}
	else{
		ans = 1;
	}
	for(ll i=2;i*i<=n;i++){
		if(n%i==0){
			ll cur = n;
			while(cur%i==0){
				cur /= i;
			}
			if((cur-1)%i==0){
				ans++;
			}
			if(n/i!=i){
				cur = n;
				ll div = n/i;
				while(cur%div==0){
					cur /= div;
				}
				if((cur-1)%div==0){
					ans++;
				}
			}
		}
	}
	//printf("%d\n",ans);
	for(ll i=2;i*i<=n-1;i++){
		if((n-1)%i==0){
			ans++;
			if((n-1)/i!=i){
				ans++;
			}
		}
	}
	printf("%d\n",ans);
}
