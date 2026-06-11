#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
#include <cstring>
#include <set>

#define rep0(i, n) for (i = 0; i < n; i++)
#define rep(s, i, n) for (i = s; i < n; i++)
using namespace std;

int sieve[1000002], cnt[1000002], a[1000002], n, m, i, j, g, t;
 
int gcd(int x, int y) {
	return y? gcd(y,x%y) : x;	
}
 
int main() {
	scanf("%d",&n);
	for(i=0;i<n;i++) {
		scanf("%d",a+i);
		if(a[i]>m) m=a[i];
		if(g) g=gcd(g,a[i]);
		else g=a[0];
	}
	if(g>1){
		printf("not coprime\n");
		return 0;
	}
	for(i=2;i<=m;i++) {
		if(sieve[i]==0) {
			sieve[i]=i;
            if((long long)i*i<=m)
			  	for(j=i*i;j<=m;j+=i){
					if(sieve[j]==0) sieve[j]=i;
			  	}
		}	
	}
	for(i=0;i<n;i++){
		j=a[i];
		while(j>1){
			t=sieve[j];
			cnt[t]++;
			if(cnt[t]>1) {
				printf("setwise coprime\n");
				return 0;
			}
			while(j%t==0) j/=t;
		}
	}
	printf("pairwise coprime\n");
	return 0;
}