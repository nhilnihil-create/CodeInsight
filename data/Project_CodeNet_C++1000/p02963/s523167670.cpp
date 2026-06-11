#include <bits/stdc++.h>
using namespace std;

int main(){
	long long s;
	scanf("%lld", &s);
	
	if(s % 1000000000 == 0)printf("0 0 1000000000 0 0 %lld\n", s / 1000000000);
	else printf("0 0 1000000000 1 %lld %lld\n", 1000000000 - s % 1000000000, (s + 1000000000 - 1) / 1000000000);
	
	return 0;
}
