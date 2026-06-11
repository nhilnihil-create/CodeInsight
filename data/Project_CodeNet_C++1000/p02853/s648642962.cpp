#include<bits/stdc++.h>
using namespace std;

#define fi first
#define se second
#define long long long
typedef pair<int,int> ii;

int main()
{
	// freopen("input.in", "r", stdin);
	int x, y;
	scanf("%d %d", &x, &y);
	if(x == 1 && y == 1) printf("1000000\n");
	else printf("%d\n", ((x > 3)? 0 : (4-x)*100000)+((y > 3)? 0 : (4-y)*100000));
}