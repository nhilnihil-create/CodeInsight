#include<bits/stdc++.h>
using namespace std;

int n;
long long x,pre[300005],R,L,mid,ans,pre2[300005];
int cnt[300005];

bool cek(long long x, int k){
	if(x==0) return 1;
//	printf("%lld %d\n",x,k);
	long long butuh = x*k;
	long long tmp = x*(pre2[300000]-pre2[x]) + pre[x];
//	printf(">> %lld %lld\n",butuh,tmp);
	if(tmp>=butuh) return 1;
	return 0;
}

int main(){
	scanf("%d",&n);
	for(int i =0;i<n;i++){
		scanf("%lld",&x);
		cnt[x]++;
	}
	for(int i= 1;i<=300000;i++){
		if(cnt[i]!=0){
			pre[cnt[i]]++;
		}
	}
	
	for(int i =1;i<=300000;i++){
		pre2[i] = pre2[i-1]+pre[i];
		pre[i] = (pre[i]*i)+pre[i-1];
		
//		printf("pre[%d] = %lld\n",i,pre[i]);
	}
	
	for(int k= 1;k<=n;k++){
		L = 0; R = n/k;
		ans = 0;
		while(L<=R){
			mid = (L+R)/2;
			if(cek(mid,k)){
				ans = max(mid,ans);
				L = mid+1;
			} else {
				R = mid-1;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}