#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int k,q;
ll d[5001];
ll n,x,m;
ll a[5005];
ll md[5005];

int main(void){
	scanf("%d%d",&k,&q);
	for(int i=0;i<k;i++){
		scanf("%lld",&d[i]);
	}
	for(int i=0;i<q;i++){
		scanf("%lld%lld%lld",&n,&x,&m);
		a[0]=x%m;
		ll ans=n-1;
		ll sum=a[0];
		for(int j=0;j<k;j++){
			md[j]=d[j]%m;
			int pos=j+1;
			ll cnt=(n-pos+k-1)/k;
			//printf("cnt %lld\n",cnt);
			if(cnt<=0)continue;
			if(md[j]==0){	
				ans-=cnt;
			}
			sum+=(ll)md[j]*cnt;
		}
		ans-=sum/m;
		printf("%lld\n",ans);
	}
	return 0;
}
