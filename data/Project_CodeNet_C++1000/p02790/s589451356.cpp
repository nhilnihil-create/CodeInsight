#include <bits/stdc++.h>
using namespace std;
#define rep(i, c) for (int i = 0; i < (int)c; i++)
int main()
{
	int a, b;
	scanf("%d%d", &a, &b);
	if(a < b) rep(i, b) cout << a;
	else rep(i, a) cout << b;
	cout << endl;
	return 0;
}