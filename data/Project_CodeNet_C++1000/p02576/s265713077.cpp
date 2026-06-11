#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
	int n, x, t; scanf("%d%d%d",&n,&x,&t);
	printf("%d\n", t*(n/x + int(n%x>0)));
}
