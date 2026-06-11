#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int n;
	scanf("%d", &n);
	double sum = 0;
	rep(i, n) {
		int a;
		scanf("%d", &a);
		sum += 1.0 / a; //int型とdouble型との演算はdoubleに暗黙変換されるので、1.0で割ることでdoubleに変換してる。
	}
	double ans = 1 / sum;
	printf("%.10f\n", ans); //ドットの後に10やると小数点10桁まで
	return 0;
}