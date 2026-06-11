#include <bits/stdc++.h>

#define PI 3.14159265358979323846264338327950288419

using namespace std;

int mina, minb;

int a, b, m;
int pa[100005];
int pb[100005];

int main(){
	scanf("%d %d %d", &a, &b, &m);
	for(int i = 1; i <= a; i++){
		scanf("%d", &pa[i]);
		if(i == 1 || pa[i] < mina){
			mina = pa[i];
		}
	}
	for(int i = 1; i <= b; i++){
		scanf("%d", &pb[i]);
		if(i == 1 || pb[i] < minb){
			minb = pb[i];
		}
	}
	int ans = mina + minb;
	for(int i = 1; i <= m; i++){
		int x, y, c;
		scanf("%d %d %d", &x, &y, &c);
		ans = min(ans, pa[x] + pb[y] - c);
	}
	printf("%d\n", ans);
	return 0;
}