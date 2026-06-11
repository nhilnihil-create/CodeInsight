#include<iostream>
#include<string>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<cmath>

using namespace std;

#define N 10005   
int main(){
	int i,j,len;
	int n;
	while(scanf("%d",&n) != EOF) {  
		if(n == 0 || n == 1) {
			printf("1\n");
			continue;
		}
		long s[N]={1, 1};
		len = 1;
		for(i = 2;i <= n; i ++){
			for(j = 0; j < len; j ++)
				s[j] = s[j] * i;
			for(j = 0;j < len - 1; j ++) {
				s[j + 1] += s[j] / 10000;
				s[j] = s[j] % 10000;
			}
			if(s[j] > 10000 ) {
				s[j + 1] = s[j] / 10000;
				s[j] = s[j] % 10000;
				len ++;       
			}
		}
		printf("%d",s[len - 1]);
		for(j = len - 2; j >= 0; j --)
			printf("%04d", s[j]);
		printf("\n");
	}   
	return 0;
}