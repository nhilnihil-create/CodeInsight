#include<cstdio>
#include<algorithm>
using namespace std;
const int MAXN=200005;
int N,A[MAXN],B[MAXN];
long long Ans;
int Check(){
	for(int i=1;i<=N;i++)
		if(B[i]!=A[i])return 0;
	return 1;
}
int Get(int x){
	if(x==0)return N;
	if(x==N+1)return 1;
	return x;
}
int main(){
	//freopen("txt.in","r",stdin);
	//freopen("hopeless.in","r",stdin);
	//freopen("hopeless.out","w",stdout);
	scanf("%d",&N);
	for(int i=1;i<=N;i++)scanf("%d",&A[i]);
	for(int i=1;i<=N;i++)scanf("%d",&B[i]);
	while(!Check()){
		int Ok=0;
		for(int i=1;i<=N;i++)
			if(B[i]-B[Get(i-1)]-B[Get(i+1)]>=A[i]){
				int t1=B[i]-A[i],t2=B[Get(i-1)]+B[Get(i+1)];
				B[i]=t1%t2+A[i];Ans+=t1/t2,Ok=1;
			}
		if(!Ok){
			printf("-1\n");
			return 0;
		}
	}
	printf("%lld\n",Ans);
}
/*
5
5 6 5 2 1
9817 1108 6890 4343 8704

5
1 2 5 6 5
8704 4343 6890 1108 9817

5
1 1 1 1 1
1 1000000001 1 1000000001 1
*/