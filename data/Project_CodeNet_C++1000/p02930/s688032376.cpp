#include<bits/stdc++.h>
int n;
int main(){
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++)
			printf("%d ",__builtin_ctz(i^j)+1);
		puts("");
	}
	return 0;
}