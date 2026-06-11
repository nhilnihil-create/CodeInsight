#include <bits/stdc++.h>
using namespace std;

int main()
{
	long long n; 
	scanf("%lld", &n);
	int cnt = 0;
	long long sq = sqrt(n)+2;
	for(int i = 2; i < sq; i++) {
		int c = 0;
		while(n % i == 0) {
			c++;
			n/=i;
		}
		int k = 1;
		while(c > 0) {
			c -= k;
			k++;
		}
		if(c < 0) k--;
		cnt += k-1;
		if(!n) break;
	}
	if(n > 1) cnt++;
	printf("%d\n", cnt);
}