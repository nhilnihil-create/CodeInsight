#include <stdio.h>
int n;
int a[30010];
int b[30010][10];
int c[30010];
int d[30010][10];
int e[10];
int cnt;
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%1d",&a[i]);
	}
	for(int i=n-1;i>=0;i--){
		for(int j=0;j<10;j++){
			b[i][j] = b[i+1][j] || a[i+1]==j;
			c[i] += b[i][j];
			if(b[i][j]){
				if(a[i+1]==j) d[i][j] = i+1;
				else d[i][j] = d[i+1][j];
			}
		}
	}
	for(int i=1;i<=n;i++){
		if(e[a[i]]==0){
			e[a[i]] = 1;
			for(int j=0;j<10;j++){
				if(d[i][j]!=0) cnt+=c[d[i][j]];
			}
		}
	}
	printf("%d\n",cnt);
}