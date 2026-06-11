#include <bits/stdc++.h>

int n;
inline int lowbit(int x){
	return x & (-x);
}

int main(){
	scanf("%d",&n);
	for(int i=1;i<n;i++){
		for(int j=i+1;j<=n;j++){
			int t = log(lowbit(i^j)) / log(2) + 1;
			printf("%d ",t);
		}
		printf("\n");
	}
	return 0;
}