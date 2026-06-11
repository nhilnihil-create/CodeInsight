#include <cstdio>
using namespace std;
int in(){ int x; scanf("%d", &x); return x; }
int main(){
	int a = in(), b = in();
	printf("%d %d %lf\n", a/b, a%b, (double)a/(double)b);
	return 0;
}