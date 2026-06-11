#include <bits/stdc++.h>
using namespace std;
int main()
{
	int n, a;
	scanf("%d%d", &n, &a);
	int l = a; //左端のりんごの味はa
	int r = a + n - 1; //右端の味

	int eat; //絶対値が0に一番近いりんごを探す
	if(r <= 0) eat = r; //右端が0以下なら右端
	else if (l >= 0) eat = l; //左端が0以上なら左端
	else eat = 0; //0の場合

	int ans = (r + l) * (r - l + 1) / 2 - eat; //公差1の等差数列なので、((初項+末項)*工数)/2

	printf("%d\n", ans);
	return 0;
}