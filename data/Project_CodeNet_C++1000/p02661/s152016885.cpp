#include <bits/stdc++.h>
#define MOD 1000000007LL
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

int n;
ll a[200005],b[200005];


int main(void){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		scanf("%lld%lld",&a[i],&b[i]);
	}
	sort(a,a+n);
	sort(b,b+n);
	if(n%2==1){
		printf("%lld\n",(b[n/2]-a[n/2])+1LL);
	}else{
		printf("%lld\n",(b[n/2]+b[n/2-1]-(a[n/2]+a[n/2-1]))+1LL);
	}
	return 0;
}
