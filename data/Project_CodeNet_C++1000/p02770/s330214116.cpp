#include<bits/stdc++.h>
using namespace std;
//FILE *fi=freopen("1.txt","r",stdin);
const int N=5005;
typedef long long LL;
int d[N];
int main(){
	int k,q,n,n1,m,x,w;LL sum;scanf("%d%d",&k,&q);
	for(int i=0;i<k;i++)scanf("%d",d+i);// nhập mảng d tính từ 0
	for(int i=0;i<q;i++){
		scanf("%d%d%d",&n,&x,&m),n--;
		x%=m,sum=w=0,n1=n/k;
		for(int j=0;j<k;j++){
			sum+=d[j]%m;
			if(d[j]%m==0)w+=n1;
		}
		sum*=n1,n1=n,n%=k;
		for(int j=0;j<n;j++){
			if(d[j]%m==0)w++;
			sum+=d[j]%m;
		}
		sum+=x;
		// tính tổng hết tất cả các các d[j] sau khi mod
		printf("%d\n",n1 - sum/m - w);
	}
	return 0;
}
