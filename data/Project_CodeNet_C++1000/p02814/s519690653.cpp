#include<iostream>
#include<algorithm>

using namespace std;

const int N = 1e5+10;
typedef long long ll;

ll a[N],n,m,ans;
int main(){
	scanf("%lld%lld",&n,&m);
	for(int i=0;i<n;i++) scanf("%lld",&a[i]);
	ans=a[0];
	for(int i=1;i<n;i++){
		ans=ans*a[i]/__gcd(ans,a[i]);
	}
	for(int i=0;i<n;i++){
		if((ans/a[i])%2==0){
			printf("0");
			return 0;
		}
	}
	printf("%lld",(m*2/ans+1)/2);
	return 0;
}