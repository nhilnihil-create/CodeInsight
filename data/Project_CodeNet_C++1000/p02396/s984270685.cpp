#include <cstdio>
using namespace std;
int in(){ int x; scanf("%d", &x); return x; }
int main(){
	int n;
	for(int i = 1;; i++){
		n = in();
		if(n == 0) break;
		printf("Case %d: %d\n", i, n);
	}
	return 0;
}