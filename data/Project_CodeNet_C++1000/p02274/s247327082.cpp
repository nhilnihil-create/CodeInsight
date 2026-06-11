//By Vlgd
#include<bits/stdc++.h>
#define INF 20000000
using namespace std;
int A[200000],n;
long long ms(int x,int y,int T[]){
	if (y-x>1){
		int m=(x+y)/2;
		int p=x,q=m,i=x;
		long long a=ms(x,m,T);
		long long b=ms(m,y,T);
		long long cnt=0;
		while (p<m||q<y){
			if (q>=y||(p<m&&A[p]<=A[q])) T[i++]=A[p++];
			else{
				T[i++]=A[q++];
				cnt+=(m-p);
			}
		}
		for (int i=x;i<y;i++) A[i]=T[i];
		return a+b+cnt; 
	}
	else return 0;
}
main(){
//	FILE *fp=fopen("5D.txt","r");
	scanf("%d",&n);
	for(int i=0;i<n;i++) scanf("%d",&A[i]);
	int *t=(int*)malloc(sizeof(int)*n);
	printf("%lld\n",ms(0,n,t));
//	for(int i=0;i<n;i++) printf("%d ",A[i]);
	free(t);
}
