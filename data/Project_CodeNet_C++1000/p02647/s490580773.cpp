#include<iostream>

using namespace std;
typedef long long ll;
const int N= 2e5+10;

ll a[N];
ll c[N];
 
int main(){
//	freopen("in.txt","r",stdin);
	int n,k;
	scanf("%d%d",&n,&k);
	for(int i = 1 ; i <= n ; i ++) scanf("%lld",&a[i]);
	if(k>=n){
		for(int i = 1 ; i <= n ; i ++) printf("%d ",n);
		return 0;	
	}
	bool f=false;
	while(!f&&k--){
		int cnt=0;
		for(int i = 0 ; i <= n ; i ++) c[i]=0;
		for(int i = 1 ; i <= n ; i ++){
			int l=max(1ll,i-a[i]);
			int r=min(1ll*n,i+a[i]);
			c[l]++;
			c[r+1]--;
		} 
		for(int i = 1 ; i <= n ; i ++) c[i]+=c[i-1];
		for(int i = 1 ; i <= n ; i ++){
			a[i]=c[i];
			if(a[i]==n) cnt++;
		}
		if(cnt==n) f=true;
	}
	for(int i = 1 ; i <= n ; i ++) printf("%d ",a[i]);

	return 0;
}