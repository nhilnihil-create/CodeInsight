#include<bits/stdc++.h>

using namespace std;

main(){
	int a;
	cin >> a;
	int b=0;
	long long c=a;
	int d=a;
	long long s=1;
	while(a > b+1){
		b=b+1;
		s=c*s;
		c=c-1;
	}
	printf("%lld\n",s);
}

