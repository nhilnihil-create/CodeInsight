#include <cstdio>
#define INF 1e9
#define eps 1e-6
typedef long long ll;

int a, b, ans; 

int main(){

	scanf("%d%d", &a, &b);
	if(a == 1 && b == 1)
		puts("1000000");
	else{
		if(a == 1) ans += 300000;
		if(a == 2) ans += 200000;
		if(a == 3) ans += 100000;
		if(b == 1) ans += 300000;
		if(b == 2) ans += 200000;
		if(b == 3) ans += 100000;
		printf("%d\n", ans);
	}

	return 0;
}
