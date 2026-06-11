#include <bits/stdc++.h>
using namespace std;
bool check(int x)
{
	int keta = 0;
	while (x) {
		keta++;
		x /= 10;
	}
	return keta % 2 == 1; //桁数が奇数ならtrueを返す
}
int main()
{
	int n;
	scanf("%d", &n);
	int ans = 0;
for(int i = 1; i <= n; i++) { //全探索
		if(check(i)) ans++; //桁数が奇数ならans++
	}
	printf("%d\n", ans);
	return 0;
}
