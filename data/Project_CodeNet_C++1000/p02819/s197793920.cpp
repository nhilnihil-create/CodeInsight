#include <cstdio>
#include <cstring>
using ll = long long;

using namespace std;

int main(){
		ll n;scanf("%lld",&n);
		ll ans;
		bool arr[100020];
		memset(arr,true,sizeof(arr));
		for(ll i=2;i<100020;i++){
				if(arr[i]){
						if(i>=n){
							ans=i;
							break;
						}
						for(ll j=i;j<100020;j+=i)arr[j]=false;
					}
			}
	   printf("%lld",ans);
	   return 0;			
	}
