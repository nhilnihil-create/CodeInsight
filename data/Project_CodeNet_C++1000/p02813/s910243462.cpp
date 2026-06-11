#include <stdio.h>
int n;
int a[10];
int b[10];
int fact[10];
int aa,bb;
int visita[10];
int visitb[10];
int abs(int x){
	return x>0?x:-x;
}
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++){
		scanf("%d",&b[i]);
	}
	fact[0] = 1;
	for(int i=1;i<=n;i++){
		fact[i] = fact[i-1]*i;
	}
	for(int i=1;i<=n;i++){
		int cnta = 0;
		int cntb = 0;
		for(int j=1;j<=n;j++){
			if(j==a[i]) break;
			if(visita[j]==0) cnta++;
		}
		for(int j=1;j<=n;j++){
			if(j==b[i]) break;
			if(visitb[j]==0) cntb++;
		}
		visita[a[i]] = visitb[b[i]] = 1;
		aa+=cnta*fact[n-i];
		bb+=cntb*fact[n-i];
	}
	printf("%d\n",abs(aa-bb));
}