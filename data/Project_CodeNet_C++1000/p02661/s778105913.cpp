#include<bits/stdc++.h>
typedef int LL;
const LL maxn=1e6+9;
LL n;
LL a[maxn],L[maxn],R[maxn];
void Solve1(){
	for(LL i=1;i<=n;++i){
		a[i]=L[i];
	}
	std::sort(a+1,a+1+n);
	LL ret1(a[n/2]+a[n/2+1]);
	for(LL i=1;i<=n;++i){
		a[i]=R[i];
	}
	std::sort(a+1,a+1+n);
	LL ret2(a[n/2]+a[n/2+1]);
	printf("%d\n",ret2-ret1+1);
}
void Solve2(){
	for(LL i=1;i<=n;++i){
		a[i]=L[i];
	}
	std::sort(a+1,a+1+n);
	LL ret1(a[n/2+1]);
	for(LL i=1;i<=n;++i){
		a[i]=R[i];
	}
	std::sort(a+1,a+1+n);
	LL ret2(a[n/2+1]);
	printf("%d\n",ret2-ret1+1);
}
int main(){
	scanf("%d",&n);
	for(LL i=1;i<=n;++i){
		scanf("%d%d",L+i,R+i);
	}
	if(n&1) Solve2();
	else Solve1();
	return 0;
}