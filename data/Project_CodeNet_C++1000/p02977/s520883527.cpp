#include <cstdio>
#include <algorithm>

using namespace std;

void out(int u, int v){
	printf("%d %d\n", u, v);
}

int main(){
	int n, tmp = 1; scanf("%d", &n);
	while(tmp <= n) tmp <<= 1;
	tmp >>= 1;
	if(tmp == n) return puts("No"), 0;
	puts("Yes");
	for(int i = 2; i < n; i += 2){
		int u = i, v = i + 1;
		out(u, 1); out(v, 1); out(u, v + n), out(v, u + n);
	} out(n + 1, 2 + n);
	if(n % 2 == 0){
		int p = n ^ 1 ^ tmp;
		out(tmp, n + n);
		if(!p) out(1, n);
		else out(p, n);
	}
	return 0;
}