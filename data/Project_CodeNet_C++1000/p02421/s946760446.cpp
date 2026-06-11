#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<functional>
#include<vector>
#include<queue>
using namespace std;
#define f(i,n) for(int i=0;i<(int)n;i++)
#define MOD 1000000009

int main(void){
    char a[101];
	char b[101];
	f(i, 101){
		a[i] = 0;
		b[i] = 0;
	}
	int n, m;
	int x, y;
	int ans = 0;
	scanf("%d", &n);
	x = 0;
	y = 0;
	f(i,n){
		scanf("%s", a);
		scanf("%s", b);
		m = strcmp(a, b);
		if (m > 0)x += 3;
		else if (m < 0)y += 3;
		else {
			x++;
			y++;
		}
	}
	printf("%d %d\n", x, y);
	return 0;
}