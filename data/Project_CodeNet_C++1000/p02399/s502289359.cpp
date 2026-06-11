#include <cstdio>

using namespace std;

int main(){
	int a, b;
	scanf("%d %d", &a, &b);
	int d = a / b;
	int r = a % b;
	double f = 1.0 * a / b;
	printf("%d %d %.5lf\n", d, r, f);
	return 0;
}